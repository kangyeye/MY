//先后指针实现
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(-100,head);
        ListNode *first=head;
        ListNode *second=dummy;

        for(int i=0;i<n;i++){
            first=first->next;
        }

        while(first){
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        ListNode *ans=dummy->next;
        return ans;
    }
};


//两次遍历、计数
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(-100,head);
        ListNode *list=head;

        //获取链表长度
        int length=0;
        while(list){
            length++;
            list=list->next;
        }

        ListNode *cur=dummy;
        for(int i=0;i<length-n;i++){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        ListNode *ans=dummy->next;
        delete dummy;
        return ans;
    }
};
