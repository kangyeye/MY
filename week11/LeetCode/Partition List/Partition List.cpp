class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small=new ListNode(0);
        ListNode *smallhead=small;
        ListNode *large=new ListNode(0);
        ListNode *largehead=large;
        while(head!=nullptr){
            if(head->val<x){
                small->next=head;
                small=small->next;
            }
            else{
                large->next=head;
                large=large->next;
            }
            head=head->next;
        }
        small->next=largehead->next;
        large->next=nullptr;
        return smallhead->next;
    }
};
