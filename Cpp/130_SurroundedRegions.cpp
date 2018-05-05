class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; ++i) {
            if(board[i][0] == 'O')
                DFS(board, i, 0);
            if(board[i][col-1] == 'O')
                DFS(board, i, col-1);
        }
        
        for(int j = 0; j < col; ++j) {
            if(board[0][j] == 'O')
                DFS(board, 0, j);
            if(board[row-1][j] == 'O')
                DFS(board, row-1, j);
        }
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
    }
    
    void DFS(vector<vector<char>>& board, int i, int j) { 
        if(board[i][j] != 'O')
            return;
        int row = board.size();
        int col = board[0].size();
        board[i][j] = 'A';
        if(i + 1 < row)
            DFS(board, i+1, j);
        if(i - 1 > 0)
            DFS(board, i-1, j);
        if(j + 1 < col)
            DFS(board, i, j+1);
        if(j - 1 > 0)
            DFS(board, i, j-1);
        
    }
};


//Union Find

class UF
{
private:
    int *id;
    int *rank;
    int count;  //count the groups
public:
    UF(int N) {
        count = N;
        id = new int[N];
        rank = new int[N];
        for(int i = 0; i < N; ++i) {
            id[i] = i;
            rank[i] = 0;
        }
    }
    
    ~UF() {
        delete [] id;
        delete [] rank;
    }
    
    int getCount() {
        return count;
    }
    
    int find(int p) {
        while(p != id[p]) { //compression to shorten the path
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    
    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
    
    void connect(int a, int b) {
        int i = find(a);
        int j = find(b);
        if(i == j)
            return;
        if(rank[i] < rank[j]) {
            id[i] = j;
        }
        else if(rank[i] > rank[j]) {
            id[j] = i;
        }
        else {
            id[i] = j;
            rank[j]++;
        }
        count--;
    }
    
    
};

class Solution {
public:
    void solve(vector<vector<char>>& board) { 
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int n = board.size();
        int m = board[0].size();
        
        UF uf(m*n+1); //one dummy node
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if( board[i][j] == 'O' && (i == 0 || i == n-1 || j == 0 || j == m-1) ) {
                    uf.connect(i*m+j, m*n);
                }
                else if(board[i][j] == 'O') {
                    if(i - 1 >= 0 && board[i-1][j] == 'O') {
                        uf.connect(i*m+j, (i-1)*m+j);
                    }
                    if(i + 1 < n && board[i+1][j] == 'O') {
                        uf.connect(i*m+j, (i+1)*m+j);
                    }
                    if(j - 1 >= 0 && board[i][j-1] == 'O') {
                        uf.connect(i*m+j, i*m+j-1);
                    }
                    if(j + 1 < m && board[i][j+1] == 'O') {
                        uf.connect(i*m+j, i*m+j+1);
                    }       
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'O' && !uf.isConnected(i*m+j, m*n)) {
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
    
};