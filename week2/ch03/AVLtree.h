#ifndef AVLTREE_H
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(int X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(int X,AvlTree T);
AvlTree Delete(int X,AvlTree T);
int Retrieve(Position P);
void PostOrderTraversal(AvlTree T);
void InOrderTraversal(AvlTree T);
void PreOrderTraversal(AvlTree T);

#endif // AVLTREE_H
