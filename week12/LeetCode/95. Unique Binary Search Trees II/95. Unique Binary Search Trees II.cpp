class Solution {
public:
    vector<TreeNode*> generateTrees(int start,int end){
        if(start>end){
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees=generateTrees(start,i-1);
            vector<TreeNode*> rightTrees=generateTrees(i+1,end);
            for(auto& left:leftTrees){
                for(auto& right:rightTrees){
                    TreeNode* curTree=new TreeNode(i);
                    curTree->left=left;
                    curTree->right=right;
                    allTrees.emplace_back(curTree);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return {};
        }
        return generateTrees(1,n);
    }
};
