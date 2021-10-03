//单链表的逆置操作
#include <stdio.h>
#include <stdlib.h>
#define OK 1
typedef int ElemType;
typedef int Status;



//-----单链表的存储结构-----//
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void CreastList_L(LinkList &L,int n){
    //创建带头结点的单链表L
    LNode *p,*q;
    int i;
    L=(LNode*)malloc(sizeof (LNode));
    L->next=NULL;   //先建立一个带头结点的单链表
    p=L;
    for (i=1;i<=n;i++){
        q=(LNode*)malloc(sizeof(LNode));   //生成新结点
        printf("Input the %dth data:",i);
        scanf("%d",&q->data);   //输入元素值
        q->next=NULL;
        p->next=q;
        p=q;
    }
}

void  ListInverse_L(LinkList &L){
    //单链表的就地逆置
    LNode *p,*q;
    p=L->next;
    L->next=NULL;
    while(p!=NULL){
        q=p->next;  //没搞懂
        p->next=L->next;
        L->next=p;
        p=q;
    }
}
void PrintList(LinkList &L){
    //输出单链表
    LNode *p=L->next;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}

int main(){
    int n;
    LinkList La;
    printf("Input the list  num:");
    scanf("%d",&n);
    CreastList_L(La,n);
    printf("Before Inverse the list is:");
    PrintList(La);
    ListInverse_L(La);
    printf("\nAfter Inverse the list is:");
    PrintList(La);
    printf("\n");
    getchar();
}
