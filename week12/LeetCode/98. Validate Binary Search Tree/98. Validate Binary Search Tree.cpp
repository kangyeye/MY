//中序遍历   
//中序遍历的二叉搜索树前节点的值比后节点的值要小
class Solution {
private:
    long long pre=LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        
        if(root==nullptr){
            return true;
        }
        if(!isValidBST(root->left)){
            return false;
        }

        if(root->val <= pre){
            return false;
        }
        pre=root->val;
        return isValidBST(root->right);
    }
};

//递归
class Solution {
public:
    bool helper(TreeNode* root,long long lower,long long upper){
        if(root==nullptr){
            return true;
        }
        if(root->val<=lower || root->val>=upper){
            return false;
        }
        return helper(root->left,lower,root->val) 
            && helper(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};
