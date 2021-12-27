//迭代
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        for(Node* cur=head;cur;cur=cur->next->next){
            Node* nodeNew=new Node(cur->val);
            nodeNew->next=cur->next;
            cur->next=nodeNew;
        }
        for(Node* cur=head;cur;cur=cur->next->next){
            cur->next->random=(cur->random)?cur->random->next:nullptr;
        }
        Node* headNew=head->next;
        for(Node* cur=head;cur;cur=cur->next){
            Node* nodeNew=cur->next;
            cur->next=cur->next->next;
            nodeNew->next=(nodeNew->next)?nodeNew->next->next:nullptr;
        }
        return headNew;
    }
};


//递归+哈希表
class Solution {
public:
    unordered_map<Node*,Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        if(!cachedNode.count(head)){
            Node* nodeNew=new Node(head->val);
            cachedNode[head]=nodeNew;
            nodeNew->next=copyRandomList(head->next);
            nodeNew->random=copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};



//哈希表
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> cachedNode;
        Node* cur=head;
        while(cur){
            cachedNode[cur]=new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur){
            cachedNode[cur]->next=cachedNode[cur->next];
            cachedNode[cur]->random=cachedNode[cur->random];
            cur=cur->next;
        }
        return cachedNode[head];
    }
};
