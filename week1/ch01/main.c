#include<stdio.h>
#include<stdlib.h>

struct list {
   int value;
   struct list * next;
};

typedef struct list item;

int main() {
   item * current, * head;
   int i;

   head = NULL;

   for(i=1;i<=10;i++) {
      current = (item *)malloc(sizeof(item));
      current->value = i;
      current->next  = head;
      head = current;
   }
   current = head;

   while(current)
   {
      printf("%d\t", current->value);
      current = current->next ;
   }
   getchar();
}
