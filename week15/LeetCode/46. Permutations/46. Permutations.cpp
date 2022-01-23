class Solution {
private:
    void dfs(const vector<int>& nums,vector<int>& used,
             vector<int>& path,vector<vector<int>>& res){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        } 
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true){
                continue;
            }
            else{
                used[i] = true;
                path.emplace_back(nums[i]);
                dfs(nums,used,path,res);
                used[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len == 0){
            return res;
        }
        vector<int> path;
        vector<int> used(len);
        dfs(nums,used,path,res);
        return res;
    }
};
