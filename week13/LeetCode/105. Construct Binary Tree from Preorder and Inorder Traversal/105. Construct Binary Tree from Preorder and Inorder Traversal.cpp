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
private:
    unordered_map<int,int> index;
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder
                       ,int preorder_left,int preorder_right
                       ,int inorder_left,int inorder_right){
        if(preorder_left > preorder_right){
            return nullptr;
        }
        int root_val = preorder[preorder_left];
        int inorder_root = index[root_val];
        TreeNode* root = new TreeNode(root_val);
        int leftNum = inorder_root - inorder_left;
        root->left = buildTreeHelper(preorder,inorder
                                    ,preorder_left+1,preorder_left+leftNum
                                    ,inorder_left,inorder_root-1);
        root->right = buildTreeHelper(preorder,inorder
                                    ,preorder_left+leftNum+1,preorder_right
                                    ,inorder_root+1,inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]] = i;
        }
        return buildTreeHelper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
