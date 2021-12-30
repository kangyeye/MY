//广度优先搜索BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr){
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ret.push_back(vector<int> ());
            int currentSize=q.size();
            for(int i=0;i<currentSize;i++){
                TreeNode* node;
                node=q.front();
                q.pop();
                ret.back().push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }
        return ret;
    }
};
