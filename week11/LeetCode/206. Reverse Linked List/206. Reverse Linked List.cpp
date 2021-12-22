//迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *cur=head;
        while(cur!=nullptr){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};

//头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummyNode=new ListNode(0,head);
        ListNode *cur=head;
        ListNode *next;
        while(cur!=nullptr&&cur->next!=nullptr){
            next=cur->next;
            cur->next=next->next;
            next->next=dummyNode->next;
            dummyNode->next=next;
        }
        return dummyNode->next;
    }
};

//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead=new ListNode(0);
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        newhead->next=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead->next;
    }
};
