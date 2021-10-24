#include<stdio.h>
#include<stdlib.h>
#include"leftheap.h"

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;    //零路径长度
};

PriorityQueue Initialize()
{
    PriorityQueue H = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if (H == NULL)
    {
        printf("FAILURE!\n");
        exit(EXIT_FAILURE);
    }
    H->Left = H->Right = NULL;
    H->Npl = 0;
    H->Element = 0;
    return H;
}
ElementType FindMin(PriorityQueue H)
{
    /*if (!H)*/
        return H->Element;
    /*return 0;*/
}
int IsEmpty(PriorityQueue H)
{
    return H->Left == NULL && H->Right == NULL;
}
void SwapChildren(PriorityQueue H)
{
    PriorityQueue Temp;
    Temp = H->Left;
    H->Left = H->Right;
    H->Right = Temp;
}
//将具有大的根植的堆与具有小的根植的堆的右子堆合并
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}
PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = Initialize();
    SingleNode->Element = X;
    H = Merge(SingleNode, H);
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;
    if (IsEmpty(H))
    {
        printf("ERROR!\n");
        return H;
    }
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

#define Get_Array_Size(Elements)  ( sizeof(Elements) / sizeof(Elements[0]) )

int main()
{
	int i;
	int Min_Element;

	PriorityQueue H;
	ElementType Elements[] = { 56,2,35,68,12,65,30,1,8,64,96 };


	H = Initialize();
	if (NULL == H) {
		printf("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < Get_Array_Size(Elements); i++) {
		Insert1(Elements[i], H);
	}

	/* test for FindMin() */
    Min_Element = FindMin(H);
    printf("%d \n", Min_Element);

    /* test for DeleteMin1() */
    H = DeleteMin1(H);
	Min_Element = FindMin(H);
	printf("%d \n", Min_Element);

	return 0;
}

