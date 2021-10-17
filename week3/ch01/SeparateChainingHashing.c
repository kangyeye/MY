#include "hash.h"
#include "stdio.h"
#include "stdlib.h"

int IsPrime(int x) {//判断是否为素数
    int i;
    for (i = 2; i * i < x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int NextPrime(int y) {//寻找最邻近素数
    while (true) {
        if (IsPrime(y))
            return y;
        else
            y++;
    }
}
int Hash(ElementType key, int TableSize) {//简单散列函数
    return key % TableSize;
}
HashTable InitializeTable(int TableSize) {//初始化散列表
    HashTable H;
    int i;

    if (TableSize < MINTABLESIZE)
        return NULL;
    H = (struct HashTbl*)malloc(sizeof(struct HashTbl));
    if (H == NULL)
        return NULL;
    H->TableSize = NextPrime(TableSize);
    H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
        return NULL;
    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            return NULL;
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}
void DestroyTable(HashTable H) {//销毁散列表
    Position h, p, q;
    int i;
    for (i = 0; i < H->TableSize; i++) {
        h = H->TheLists[i];
        p = h->Next;
        while (p) {
            q = p->Next;
            if (!q) {
                free(p);
                p = NULL;
            }
            else {
                free(p);
                p = q;
            }
        }
    }
}
Position Find(ElementType key, HashTable H) {//通过关键字查找元素，返回位置
    Position P;
    List L;
    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != key)
        P = P->Next;
    return P;
}
void Insert(ElementType key, HashTable H) {//插入关键字
    Position Pos, NewElement;
    List L;
    Pos = Find(key, H);
    if (Pos == NULL) {
        NewElement = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (NewElement == NULL)
            exit(0);
        else {
            L = H->TheLists[Hash(key, H->TableSize)];
            NewElement->Next = L->Next;
            NewElement->Element = key;
            L->Next = NewElement;
        }
    }
}
ElementType Retrieve(Position P) {//定位
    return P->Element;
}
int Delete(ElementType key, HashTable H){//删除关键字
    Position Pos, L, Temp;
    Pos = H->TheLists[Hash(key, H->TableSize)];
    L = Pos;
    while (L != NULL && L->Next != NULL && L->Next->Element != key) {
        L = L->Next;
    }
    if (L == NULL)
        return 0;
    else if (L->Next == NULL)
        free(L);
    else {
        Temp = L->Next;
        L->Next = L->Next->Next;
        free(Temp);
    }
    return 1;
}

int main()//TEST
{
    Position p;

    HashTable table = InitializeTable(10);

    Insert(0, table);
    Insert(1, table);
    Insert(81, table);
    Insert(4, table);
    Insert(64, table);
    Insert(25, table);
    Insert(16, table);
    Insert(36, table);
    Insert(9, table);
    Insert(49, table);

    p = Find(81, table);
    if (p == NULL)
        printf("Can't find\n");
    else
        printf("Find %d \n", p->Element);

    if (Delete(81, table)) {
        printf("Delete 81\n");
    }

    p = Find(81, table);
    if (p == NULL)
        printf("Can't find\n");
    else
        printf("Find %d \n", p->Element);

    DestroyTable(table);
    return 0;
}
