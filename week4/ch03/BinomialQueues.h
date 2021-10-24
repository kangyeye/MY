#pragma once
typedef long ElementType;

#define Infinity    (30000L)  
#ifndef  _BinHeap_H  
#define _BinHeap_H  

#define MaxTrees    (14)        //二项队列中的二项树高度最大为13；  
#define Capacity    (16383)     //高度0,1,2,3，...，13的二项树节点数目之和  

struct BinNode;                     //二项树节点  
typedef struct BinNode* BinTree;    //二项树  
struct Collection;
typedef struct Collection* BinQueue;

BinQueue Initialize(void);
void Destroy(BinQueue H);
BinQueue MakeEmpty(BinQueue H);
BinQueue Insert(ElementType Item, BinQueue H);
ElementType DeleteMin(BinQueue H);
BinTree CombineTrees(BinTree T1, BinTree T2);     //合并两棵相同大小的树  
BinQueue Merge(BinQueue H1, BinQueue H2);
ElementType FindMin(BinQueue H);
int IsEmpty(BinQueue H);
int IsFull(BinQueue H);
#endif  
