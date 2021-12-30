//方法一：显式中序遍历
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& nums){
        if(root==nullptr){
            return;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    pair<int,int> findTwoSwapped(vector<int>& nums){
        int Index1 = -1;
        int Index2 = -2;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                Index2=i+1;
                if(Index1 == -1){
                    Index1=i;
                }
                else{
                    break;
                }
            }
        }
        int x=nums[Index1] , y=nums[Index2];
        return {x,y};
    }
    void recover(TreeNode* root,int count,int x,int y){
        if(root!=nullptr){
            if(root->val == x || root->val == y){
                root->val = root->val == x ? y : x;
                if(--count == 0){
                    return;
                }
            }
            recover(root->left,count,x,y);
            recover(root->right,count,x,y);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        pair<int,int> swapped=findTwoSwapped(nums);
        recover(root,2,swapped.first,swapped.second);
    }
};


//方法二：隐式中序遍历
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* x=nullptr;
        TreeNode* y=nullptr;
        TreeNode* pre=nullptr;

        while(root!=nullptr || !stack.empty()){
            while(root!=nullptr){
                stack.push(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            if(pre!=nullptr && root->val < pre->val){
                y=root;
                if(x==nullptr){
                    x=pre;
                }
                else{
                    break;
                }  
            }
            pre=root;
            root=root->right;
        }
        swap(x->val,y->val);
    }
};
