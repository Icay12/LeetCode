class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) {
            return;  
        }
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == '.') {
                    for(char num = '1'; num <= '9'; ++num) {
                        if(isValidSudoku(board,i,j,num)) {
                            board[i][j] = num;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board,int row,int col,char c) {
        for(int i = 0; i < 9; ++i) {
            if(board[row][i] != '.' && board[row][i] == c) return false;
            if(board[i][col] != '.' && board[i][col] == c) return false;
            if(board[row/3*3 + i/3][col/3*3 + i%3] != '.' && board[row/3*3 + i/3][col/3*3 + i%3]== c) return false;
        }
        return true;
    }
};