//头插法
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummyNode=new ListNode(0,head);
        ListNode *ptr=dummyNode;
        for(int i=1;i<left;i++){
            ptr=ptr->next;
        }
        ListNode *cur=ptr->next;
        ListNode *next=cur->next;
        for(int i=0;i<right-left;i++){
            cur->next=next->next;
            next->next=ptr->next;
            ptr->next=next;
            next=cur->next;
        }
        return dummyNode->next;
    }
};

//穿针引线
class Solution {
private:
    void reverseLinkedList(ListNode *head){
        ListNode *pre=nullptr;
        ListNode *cur=head;
        while(cur!=nullptr){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(0,head);    
        ListNode *cur=dummy;
        for(int i=1;i<left;i++){
            cur=cur->next;
        }
        ListNode *precursor=cur;
        int n=right-left+1;
        for(int i=0;i<n;i++){
            cur=cur->next;
        }
        ListNode *rightNode=cur;
        ListNode *leftNode=precursor->next;
        ListNode *successor=rightNode->next;
        
        precursor->next=nullptr;
        rightNode->next=nullptr;

        reverseLinkedList(leftNode);

        precursor->next=rightNode;
        leftNode->next=successor;

        return dummy->next;
    }
};
