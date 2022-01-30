//方法一 空间 vector<vector<int>> C(rowIndex + 1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> C(rowIndex + 1);
        for(int i = 0; i <= rowIndex; i++){
            C[i].resize(i+1);
            C[i][0] = C[i][i] = 1;
            for(int j = 1; j < i; j++){
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        return C[rowIndex];
    }
};

//方法二 空间 vector<int> pre, cur滚动数组
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre, cur;
        for(int i = 0; i <= rowIndex; i++){
            cur.resize(i+1);
            cur[0] = cur[i] = 1;
            for(int j = 1; j < i; j++){
                cur[j] = pre[j-1] + pre[j];
            }
            pre = cur;
        }
        return pre;
    }
};

//方法三： 空间vector<int> row(rowIndex + 1) 倒序计算 可以避免前面的数字被覆盖
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for(int i = 0; i <= rowIndex; i++){
            for(int j = i; j > 0; j--){
                row[j] += row[j-1];
            }
        }
        return row;
    }
};
