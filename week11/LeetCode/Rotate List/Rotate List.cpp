/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length=0;

        if(head==nullptr || k==0 || head->next==nullptr){
            return head;
        }

        ListNode *cur=head;
        while(cur->next!=nullptr){
            cur=cur->next;
            length=length+1;
        }
        ListNode *tail=cur;
        tail->next=head;
        length=length+1;
        int n=length-k%length+1;


        cur=head;
        for(int i=1;i<n-1;i++){
            cur=cur->next;
        }
        ListNode *newhead=cur->next;
        cur->next=nullptr;
        return newhead;
    }
};
