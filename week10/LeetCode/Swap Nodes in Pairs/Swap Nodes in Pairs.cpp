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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(-100,head);
        ListNode *cur=dummy;
        while(cur->next!=nullptr && cur->next->next!=nullptr){
            ListNode *Node1=cur->next;
            ListNode *Node2=cur->next->next;
            cur->next=Node2;
            Node1->next=Node2->next;
            Node2->next=Node1;
            cur=Node1;
        }
        return dummy->next;
    }
};
