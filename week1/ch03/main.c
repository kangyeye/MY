//交换链表的两个元素
#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
	int data;
	struct node* next;
}linklist;
//typedef struct node linklist;
 
linklist *L=NULL;
 
linklist* createList(int *a,int len)
{
 // int data;
  linklist *pCurrent,*rear;
  L=(linklist*)malloc(sizeof(linklist));
  rear=L;
 
  int count=0;
  while(count<len)
  {
	  pCurrent=(linklist*)malloc(sizeof(linklist));
	  pCurrent->data=a[count];
	  rear->next=pCurrent;
	  rear=pCurrent;
	  count++;
  }
  rear->next=NULL;
  return L;
}
//返回前驱节点
node* FindPre(node* head,node* p)
{
  node *q=head;
  while(q->next!=p&&q!=NULL)
  {
	  q=q->next;
  }
  return q;
 
}

linklist* Swap(linklist *head,node *p,node *q)
{
	if(head==NULL||p==NULL||q==NULL)
	{
		printf("invalid parameter:NULL.");
		return head;
	}
	if(p->data==q->data)
		return head;
	if(p->next==q)
	{
     node* pre_p=FindPre(head,p);
	 pre_p->next=q;
	 p->next=q->next;
	 q->next=p;
	}
	else if(q->next==p)
	{
      node* pre_q=FindPre(head,q);
	  pre_q->next=p;
	  q->next=p->next;
	  p->next=q;
	}
	else if(p!=q)
	{
     node* pre_q2=FindPre(head,q);
	  node* pre_p2=FindPre(head,p);
	  node* after_p=p->next;
      p->next=q->next;
      q->next=after_p;
 
	 pre_q2->next=p;
	 pre_p2->next=q;
	 
	 
	}
	return head;
}
 
int main()
{
	int i,j;
	int a[]={4,5,1,6,12,9,23,15,19};
	int lens=sizeof(a)/sizeof(a[0]);
 
	createList(a,lens);
   linklist* p;
   p=L;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
   node *temp1,*temp2;
   temp1=(node*)malloc(sizeof(node));
   temp2=(node*)malloc(sizeof(node));
    temp1=L->next;
	temp2=L->next;
   for(i=0;i<3;i++)
   {
	   temp1=temp1->next;
   }
   for(j=0;j<6;j++)
   {
     temp2=temp2->next;
   }
  
   printf("\n");
   Swap(L,temp1,temp2);
   p=L;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
		
	return 0;
}
