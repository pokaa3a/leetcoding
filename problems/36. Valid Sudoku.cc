class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]={0}, cols[9][9]={0}, subs[9][9]={0};
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!='.'){
                    int num = board[i][j]-'1';
                    int block = (i/3)*3+j/3;
                    if(rows[i][num]||cols[j][num]||subs[block][num]) return false;
                    rows[i][num] = true;
                    cols[j][num] = true;
                    subs[block][num] = true;
                }
            }
        }
        return true;
    }
};