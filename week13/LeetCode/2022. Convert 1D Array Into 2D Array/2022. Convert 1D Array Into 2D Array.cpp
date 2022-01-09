class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret;
        if(original.size() != m * n){
            return ret;
        }
        for(auto it = original.begin(); it != original.end(); it = it + n){
                ret.emplace_back(it, it + n);
        }
        return ret;
    }
};
