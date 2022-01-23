//递归   会超出时间限制
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int money = root->val;
        if(root->left){
            money += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            money += rob(root->right->left) + rob(root->right->right);
        }
        return max(rob(root->left) + rob(root->right),money);
    }
};

//记忆化搜索
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> memo;
        return memoRob(root,memo);
    }
    int memoRob(TreeNode* node,unordered_map<TreeNode*,int>& memo){
        if(memo.count(node)){
            return memo[node];
        }
        if(node == nullptr){
            return 0;
        }
        int money = node->val;
        if(node->left){
            money += memoRob(node->left->left,memo)
                   + memoRob(node->left->right,memo);
        }
        if(node->right){
            money += memoRob(node->right->left,memo)
                   + memoRob(node->right->right,memo);
        }
        memo[node] = max(memoRob(node->left,memo)
                   + memoRob(node->right,memo),money);
        return memo[node];
    }
};

//动态规划
class Solution {
public:
    pair<int,int> helper(TreeNode* node){
        if(node == nullptr){
            return make_pair(0,0);
        }
        pair<int,int> left = helper(node->left);
        pair<int,int> right = helper(node->right);
        pair<int,int> result;
        result.first = max(left.first,left.second) 
                     + max(right.first,right.second);
        
        result.second = left.first + right.first + node->val;
        return result;
    }
    int rob(TreeNode* root) {
        pair<int,int> result = helper(root);
        return max(result.first,result.second);
    }

};
