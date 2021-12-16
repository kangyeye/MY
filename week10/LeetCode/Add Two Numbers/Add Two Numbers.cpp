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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int carry = 0;
        while(l1||l2){
            int n1 = l1 ? l1->val : 0;    //如果l1不为空，则n1 = l1->val;如果l1为空，则n1 = 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if(!head){
                head = tail = new ListNode(sum % 10);     //初始情况，链表为空
            }
            else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry > 0){    //最后一步的进位
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head;
    }
};
