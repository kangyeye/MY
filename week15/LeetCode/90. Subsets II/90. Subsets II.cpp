class Solution {
private:
    void dfs(const vector<int>& nums,vector<int>& path,
             int begin,vector<vector<int>>& res){
        res.emplace_back(path);
        for(int i = begin; i < nums.size(); i++){
            if(i > begin && nums[i] == nums[i - 1]){
                continue;
            }
            path.emplace_back(nums[i]);
            dfs(nums,path,i+1,res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(len == 0){
            return res;
        }
        vector<int> path;
        dfs(nums,path,0,res);
        return res;
    }
};
