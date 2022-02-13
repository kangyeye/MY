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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummyNode = new ListNode(-1,head);
        ListNode* preLeft = dummyNode;
        ListNode* preRight = dummyNode;
        ListNode* left = head;
        ListNode* right = head;
        for(int i = 1; i < k; i++){
            preLeft = preLeft->next;
            left = left->next;
        }
        ListNode* Nextleft = left->next;
        ListNode* cur = left;
        while(cur->next){
            cur = cur->next;
            preRight = preRight->next;
            right = right->next;
        }
        if(preLeft == right){
            left->next = right;
            preRight->next = left;
            right->next = Nextleft; 
        }else if(right == Nextleft){
            left->next = right->next;
            right->next = left;
            preLeft->next = right;
        }else{
            left->next = right->next;
            preRight->next = left;
            preLeft->next = right;
            right->next = Nextleft;
        }
        return dummyNode->next;
    }
};
