
//模拟  声明visited数组来保存是否被访问过的状态
class Solution {
    static constexpr int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        if(m == 0 || n == 0){
            return {};
        }
        vector<vector<bool>> visited(m,vector<bool>(n));
        vector<int> res(total);
        
        int row = 0;
        int column = 0;
        int directionIndex = 0;
        for(int i = 0; i < total; i++){
            res[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if(nextRow < 0 || nextRow >= m
            || nextColumn < 0 || nextColumn >= n
            || visited[nextRow][nextColumn]){
                directionIndex = (directionIndex + 1) % 4;
            }
            row +=directions[directionIndex][0];
            column +=directions[directionIndex][1];
        }
        return res;
    }
};

//省去设立的visited数组   
//声明四个变量来保存此时的上边界、下边界、左边界和有边界

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
