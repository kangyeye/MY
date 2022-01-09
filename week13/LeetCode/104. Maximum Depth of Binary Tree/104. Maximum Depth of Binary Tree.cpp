//层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int currentSize=q.size();
            for(int i=0;i<currentSize;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};

//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
