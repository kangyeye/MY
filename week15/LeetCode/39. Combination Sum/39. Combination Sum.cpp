class Solution {
private:
    void dfs(vector<int>& candidates,int begin,int target,
             vector<int>& path,vector<vector<int>>& res){
        if(target<0){
            return;
        }
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = begin; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            dfs(candidates,i,target - candidates[i],path,res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> res;
        if(len == 0){
            return res;
        }
        vector<int> path;
        dfs(candidates,0,target,path,res);
        return res;
    }
};
