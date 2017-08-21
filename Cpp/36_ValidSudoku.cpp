class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int existRow[9][9] = {0},existCol[9][9] = {0},existBox[9][9] = {0};
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                char c = board[i][j];
                if(c != '.') {
                    int num = c - '0' - 1;
                    int k = i/3*3 + j/3;
                    if(existRow[i][num] || existCol[j][num] || existBox[k][num]) {
                        return false;
                    }
                    else {
                        existRow[i][num] = existCol[j][num] = existBox[k][num] = 1;
                    }
                }
            }
        }
        return true;
    }
};