class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0], j = click[1];
        if(board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }
        int m = board.size(), n = board[0].size();
        reveal(board, i, j, m, n);
        return board;
    }
    
    void reveal(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(board[i][j] == 'M')
            return;
        
        int count = 0;

        if(i-1 >=0 && j-1>=0 && board[i-1][j-1] == 'M') count++;
        if(i-1 >=0 && board[i-1][j] == 'M') count++;
        if(i-1 >=0 && j+1<n && board[i-1][j+1] == 'M') count++;
        if(j-1>=0 && board[i][j-1] == 'M') count++;
        if(j+1<n && board[i][j+1] == 'M') count++;
        if(i+1 <m && j-1>=0 && board[i+1][j-1] == 'M') count++;
        if(i+1 <m && board[i+1][j] == 'M') count++;
        if(i+1 <m && j+1<n && board[i+1][j+1] == 'M') count++;
        
        if(count > 0) {
            board[i][j] = '0'+count;
            return;
        }
        
        board[i][j] = 'B';
        if(i-1 >=0 && j-1>=0 && board[i-1][j-1] == 'E') reveal(board,i-1,j-1, m,n);
        if(i-1 >=0 && board[i-1][j] == 'E') reveal(board,i-1,j, m,n);
        if(i-1 >=0 && j+1<n && board[i-1][j+1] == 'E') reveal(board,i-1,j+1, m,n);
        if(j-1>=0 && board[i][j-1] == 'E') reveal(board,i,j-1, m,n);
        if(j+1<n && board[i][j+1] == 'E') reveal(board,i,j+1, m,n);
        if(i+1 <m && j-1>=0 && board[i+1][j-1] == 'E') reveal(board,i+1,j-1, m,n);
        if(i+1 <m && board[i+1][j] == 'E') reveal(board,i+1,j, m,n);
        if(i+1 <m && j+1<n && board[i+1][j+1] == 'E') reveal(board,i+1,j+1, m,n);
        return;
    }
};