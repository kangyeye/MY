#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X，SearchTree T );
Position Fi ndMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X，SearchTree T );
SearchTree Delete( ElementType X，SearchTree T );
int Retrieve( Position P );
void InorderTraverse(SearchTree T);//中序遍历
void PreorderTraverse(SearchTree T);//先序遍历
void postOrderTraverse(SearchTree T);//后序遍历

#endif /*_Tree_H */
