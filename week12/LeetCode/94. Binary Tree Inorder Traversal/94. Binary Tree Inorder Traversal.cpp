//递归
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &res){
        if(root==nullptr){
            return;
        }
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};

//迭代 将递归所需的栈显式给出
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        while(root!=nullptr || !stack.empty()){
            while(root!=nullptr){
                stack.push(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return  res;
    }
};
