class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, std::string(n, '.'));
        solveNQueen(res,board,0,n);
        return res;
    }
    void solveNQueen(vector<vector<string>>& res, vector<string>& board, int start, int n) {
        if(start == n) {
            res.push_back(board);
            return;
        }
        // vector<string> board(n, std::string(n, '.'));
        for(int i = 0; i < n; ++i) {
            if(checkQueen(board, start, i, n) == 0)
                continue;
            else {
                board[start][i] = 'Q';
                solveNQueen(res, board, start+1, n);
                board[start][i] = '.'; 
            }
        }
    }
    int checkQueen(vector<string> board, int x, int y, int n) {
        for(int i = 0; i < x; ++i) {
            if(board[i][y] == 'Q')
                return 0;
        }
        for(int i = x-1, j = y-1; i >= 0 && j >=0; --i, --j) {
            if(board[i][j] == 'Q')
                return 0;
        }
        for(int i = x-1, j = y+1; i >= 0 && j < n; --i, ++j) {
            if(board[i][j] == 'Q')
                return 0;
        }
        return 1;
    }
};