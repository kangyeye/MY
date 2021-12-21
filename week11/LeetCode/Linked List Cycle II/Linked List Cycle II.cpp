//快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(true){
            if(fast==nullptr||fast->next==nullptr){
                return NULL;
            }
            fast=fast->next->next; 
            slow=slow->next;  
            if(slow==fast){
                ListNode *ptr=head;
                while(ptr!=slow){
                    ptr=ptr->next;
                    slow=slow->next;
                }
                return ptr;
            }  
        }
    }
};


//哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while(head!=nullptr){
            if(visited.count(head)){
                return head;
            }
            else{
                visited.insert(head);
                head=head->next;
            }
        }
        return nullptr;
    }
};
