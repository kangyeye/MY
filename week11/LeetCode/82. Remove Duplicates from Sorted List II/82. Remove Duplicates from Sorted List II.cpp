//迭代（一次遍历）
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *dummmyNode=new ListNode(0,head);
        ListNode *pre=dummmyNode;
        ListNode *cur=head;
        while(cur!=nullptr){
            while(cur->next!=nullptr&&cur->val==cur->next->val){
                cur=cur->next;
            }
            if(pre->next==cur){
                pre=pre->next;
            }
            else{
                pre->next=cur->next;
            }
            cur=cur->next;
        }
        return dummmyNode->next;
    }
};
