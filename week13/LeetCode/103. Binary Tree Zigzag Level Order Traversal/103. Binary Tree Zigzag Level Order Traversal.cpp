class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;
        while(!nodeQueue.empty()){
            deque<int> levelList;
            int currentSize = nodeQueue.size();
            for(int i=0;i<currentSize;i++){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if(isOrderLeft){
                    levelList.push_back(node->val);
                } else{
                    levelList.push_front(node->val);
                }
                if(node->left){
                    nodeQueue.push(node->left);
                }
                if(node->right){
                    nodeQueue.push(node->right);
                }
            }
            ret.push_back(vector<int>{levelList.begin(),levelList.end()});
            isOrderLeft = !isOrderLeft;
        }
        return ret;
    }
};
