typedef int ElementType;
#ifndef HASH_H_
#define HASH_H_
#define MINTABLESIZE 5
#define MAXTABLESIZE 100
struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

int IsPrime(int x);
int NextPrime(int y);
int Hash(ElementType key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType key, HashTable H);
void Insert(ElementType key, HashTable H);
ElementType Retrieve(Position P);
int Delete(ElementType key, HashTable H);
#endif /* HASH_H_ */

struct ListNode {
	ElementType Element;
	Position Next;
};
typedef Position List;
struct HashTbl {
	int TableSize;
	List * TheLists;
};  
