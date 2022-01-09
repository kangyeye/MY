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
    TreeNode* buildTreeHelper(const vector<int>& inorder,const vector<int>& postorder
                             ,int inorder_left,int inorder_right
                             ,int postorder_left,int postorder_right){
        if(postorder_left > postorder_right){
            return nullptr;
        }
        int root_val = postorder[postorder_right];
        int inorder_root = index[root_val];
        TreeNode* root = new TreeNode(root_val);
        int leftNum = inorder_root - inorder_left;
        
        root->left = buildTreeHelper(inorder,postorder
                                    ,inorder_left,inorder_root-1
                                    ,postorder_left,postorder_left+leftNum-1);
        root->right = buildTreeHelper(inorder,postorder
                                    ,inorder_root+1,inorder_right
                                    ,postorder_left+leftNum,postorder_right-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]] = i;
        }
        return buildTreeHelper(inorder,postorder,0,n-1,0,n-1);
    }
};
