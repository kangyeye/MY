/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr){
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ret.push_back(vector<int> ());
            int currentSize = q.size();
            for(int i=0;i<currentSize;i++){
                TreeNode* node = q.front();
                q.pop();
                ret.back().push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
