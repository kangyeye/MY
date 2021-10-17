#ifndef HASH_H_
#define HASH_H_

#define MAXTABLESIZE 200
#define MINTABLESIZE 1

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;

struct HashTbl;
typedef struct HashTbl* HashTable;

int IsPrime(int x);
int NextPrime(int y);
int Hash(ElementType key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType key, HashTable H);
void Insert(ElementType key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
int Delete(ElementType key, HashTable H);
HashTable Rehash(HashTable H);

#endif /*HASH_H_*/

enum KindOfEntry{Legitimate,Empty,Deleted};

struct  HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
	unsigned int TableSize;
	Cell* TheCells;
};
