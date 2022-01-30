class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> res;
        while(true){
            for(int i = left;i <= right; i++){
                res.emplace_back(matrix[up][i]);
            }
            if(++up > down) break;

            for(int i = up;i <= down; i++){
                res.emplace_back(matrix[i][right]);
            }
            if(--right < left) break;

            for(int i = right;i >= left; i--){
                res.emplace_back(matrix[down][i]);
            }
            if(--down < up) break;

            for(int i = down;i >= up; i--){
                res.emplace_back(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return res;
    }
};
