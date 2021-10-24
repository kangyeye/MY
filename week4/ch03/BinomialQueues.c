#include "binomial.h"  
#include <stdio.h>  
#include <stdlib.h>  

typedef struct BinNode* Position;

struct BinNode
{
    ElementType Element;
    Position LeftChild;
    Position NextSibling;
};

struct Collection
{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];     //数组，该数组每个元素都是一棵二项树  
};

BinQueue Initialize()
{
    BinQueue H;
    int i = 0;
    H = (BinQueue)malloc(sizeof(struct Collection));
    if (H == NULL) {
        printf("Out of space!!\n");
        return NULL;
    }
    H->CurrentSize = 0;      //设置二项队列初始大小为0，每棵二项树均为NULL  
    for (i = 0; i < MaxTrees; ++i) {
        H->TheTrees[i] = NULL;
    }
    return H;
}

static void DestroyTree(BinTree T)
{
    //递归删除二项树的所有节点  
    if (T != NULL) {
        DestroyTree(T->LeftChild);
        DestroyTree(T->NextSibling);
        free(T);
    }
}

void Destroy(BinQueue H)
{
    //释放二项队列所占空间：通过删除所有的二项树完成  
    int i = 0;
    for (i = 0; i < MaxTrees; ++i) {
        DestroyTree(H->TheTrees[i]);
    }
}

BinQueue MakeEmpty(BinQueue H)
{
    int i = 0;
    Destroy(H);     //首先释放H所占空间  
    for (i = 0; i < MaxTrees; ++i) {
        H->TheTrees[i] = NULL;
    }
    H->CurrentSize = 0;      //二项队列当前大小  
    return H;
}

BinQueue Insert(ElementType Item, BinQueue H)
{
    BinTree NewNode;    //二项树B0  
    BinQueue OneItem;   //只有B0的二项队列  
    NewNode = (BinTree)malloc(sizeof(struct BinNode));
    if (NewNode == NULL) {
        printf("Out of space!\n");
        return H;
    }
    NewNode->Element = Item;
    NewNode->LeftChild = NewNode->NextSibling = NULL;
    OneItem = Initialize();
    OneItem->CurrentSize = 1;
    OneItem->TheTrees[0] = NewNode;
    return Merge(H, OneItem);   //合并单节点的二项树构成的二项队列与H  
}

ElementType FindMin(BinQueue H)
{
    int i = 0;
    ElementType MinItem;
    if (IsEmpty(H)) {
        printf("Empty binomial queue");
        return -1;
    }
    MinItem = Infinity;
    //遍历二项队列中的所有二项树，比较它们的根  
    for (i = 0; i < MaxTrees; ++i) {
        if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem) {
            MinItem = H->TheTrees[i]->Element;
        }
    }
    return MinItem;
}

int IsEmpty(BinQueue H)
{
    return H->CurrentSize == 0;      //currentsize存放二项队列中节点的个数  
}

int IsFull(BinQueue H)
{
    return H->CurrentSize == Capacity;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
    //合并相同大小的两颗二项树  
    if (T1 == NULL)
        return T2;
    else if (T2 == NULL)
        return T1;
    if (T1->Element > T2->Element)
        return CombineTrees(T2, T1);
    //根大的树做为根小的树的左儿子  
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;
    int i = 0, j = 0;
    //首先判断合并是否会超出二项队列限制的大小  
    if (H1->CurrentSize + H2->CurrentSize > Capacity) {
        printf("Merge would exceed capacity!\n");
        return H1;
    }
    H1->CurrentSize += H2->CurrentSize;
    //遍历H1，H2中所有的二项树  
    for (i = 0, j = 1; j <= H1->CurrentSize; ++i, j *= 2) {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];
        //若T1为空，!!T1则为0，否则为1  
        switch (!!T1 + 2 * (!!T2) + 4 * (!!Carry)) {
        case 0:
        case 1:
            break;
        case 2:
            //只有T2存在，直接将T2放入二项队列H1中对应的位置；  
            H1->TheTrees[i] = T2;
            H2->TheTrees[i] = NULL;
            break;
        case 3:
            //T1与T2均存在，合并相同大小的二项树  
            Carry = CombineTrees(T1, T2);
            H1->TheTrees[i] = NULL;
            H2->TheTrees[i] = NULL;
            break;
        case 4:
            //由上一步合并而得的二项树作为二项队列H1的一部分  
            H1->TheTrees[i] = Carry;
            Carry = NULL;
            break;
        case 5:
            Carry = CombineTrees(T1, Carry);
            H1->TheTrees[i] = NULL;
            break;
        case 6:
            Carry = CombineTrees(T2, Carry);
            H2->TheTrees[i] = NULL;
            break;
        case 7:
            H1->TheTrees[i] = Carry;
            Carry = CombineTrees(T1, T2);
            H2->TheTrees[i] = NULL;
            break;
        }
    }
    return H1;
}

ElementType DeleteMin(BinQueue H)
{
    int i = 0, j = 0;
    int MinTree;        //用来存放根最小的二项树的高度  
    BinQueue DeletedQueue;
    Position DeletedTree, OldRoot;
    ElementType MinItem;

    if (IsEmpty(H)) {
        printf("Empty binomial queue!\n");
        return -1;
    }

    MinItem = Infinity;
    //遍历二项队列，找出根元素最小的二项树  
    for (i = 0; i < MaxTrees; ++i) {
        if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem) {
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }

    DeletedTree = H->TheTrees[MinTree];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);      //删除根元素；  
    DeletedQueue = Initialize();

    //将1左移MinTree位，即得到高度为MinTree的二项树的大小  
    //因为高度为k的二项树的大小是2^k,减1是因为删除了根  
    DeletedQueue->CurrentSize = (1 << MinTree) - 1;

    //将删除根后的各个子树构成新的二项队列  
    for (j = MinTree - 1; j >= 0; --j) {
        DeletedQueue->TheTrees[j] = DeletedTree;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[j]->NextSibling = NULL;
    }

    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -= DeletedQueue->CurrentSize + 1;  //新二项队列的大小；  
    Merge(H, DeletedQueue);
    return MinItem;
}
