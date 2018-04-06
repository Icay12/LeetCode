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