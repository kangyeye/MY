class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int column[9][9];
        int subboxes[3][3][9];

        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        memset(subboxes,0,sizeof(subboxes));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                 if(board[i][j]!='.'){
                     int count=board[i][j]-'1';
                     row[i][count]++;
                     column[j][count]++;
                     subboxes[i/3][j/3][count]++;
                     if(row[i][count]>1
                        ||column[j][count]>1
                        ||subboxes[i/3][j/3][count]>1){
                            return false;
                        }
                 }
            }
        }
        return true;
    }
};
