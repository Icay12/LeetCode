//DFS
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.size() == 0 || grid[0].size() == 0 )
            return res;
        
        for(int i = 0 ; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    res += 1;
                    
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j) {
        
        grid[i][j] = '0';
        if(i - 1 >= 0 && grid[i-1][j] == '1') 
            DFS(grid, i-1, j);
        if(j - 1 >= 0 && grid[i][j-1] == '1') 
            DFS(grid, i, j-1);
        if(i+1 < grid.size() && grid[i+1][j] == '1') 
            DFS(grid, i+1, j);
        if(j+1 < grid[0].size() && grid[i][j+1] == '1') 
            DFS(grid, i, j+1);
    }
     
};



//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.size() == 0 || grid[0].size() == 0 )
            return res;
        
        for(int i = 0 ; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    res += 1;
                    
                    BFS(grid, i, j);
                }
            }
        }
        return res;
    }
    
    void BFS(vector<vector<char>>& grid, int i, int j) {
        queue<vector<int>> q;
    
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()) {
            
            int i = q.front()[0];
            int j = q.front()[1];
            // grid[i][j] = '0';  //if put it here, a neighbor will be visited a lot of times
            q.pop();
            if(i - 1 >= 0 && grid[i-1][j] == '1') {
                q.push({i-1, j});
                grid[i-1][j] = '0';  //should put it here
            }
            if(j - 1 >= 0 && grid[i][j-1] == '1')  {
                q.push({i,j-1});
                grid[i][j-1] = '0';  //should put it here
            }
            if(i+1 < grid.size() && grid[i+1][j] == '1') {
                q.push({i+1,j});
                grid[i+1][j] = '0';  //should put it here
            }
            if(j+1 < grid[0].size() && grid[i][j+1] == '1') {
                q.push({i,j+1});
                grid[i][j+1] = '0';  //should put it here
            }
        }

    }
     
};



// Union Find

class UF {
private:
    int *id;
    int *rank;
    int count;
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
        while(p != id[p]) {
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
        if(rank[i] > rank[j])
            id[j] = i;
        else if(rank[j] > rank[i])
            id[i] = j;
        else {
            id[i] = j;
            rank[j]++;
        }
        count--;
    }
    
    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0 )
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        UF uf(n*m+1);
        for(int i = 0 ; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    if(i - 1 >= 0 && grid[i-1][j] == grid[i][j])
                        uf.connect(i*m+j, (i-1)*m+j);
                    if(i + 1 < n && grid[i+1][j] == grid[i][j])
                        uf.connect(i*m+j, (i+1)*m+j);
                    if(j - 1 >= 0 && grid[i][j-1] == grid[i][j])
                        uf.connect(i*m+j, i*m+j-1);
                    if(j + 1 < m && grid[i][j+1] == grid[i][j])
                        uf.connect(i*m+j, i*m+j+1);
                }
                else {
                    uf.connect(i*m+j, n*m);
                }
                
            }
        }
        return uf.getCount()-1;
    }

     
};