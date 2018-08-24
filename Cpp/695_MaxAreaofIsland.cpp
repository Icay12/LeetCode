class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); ++i ) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1)
                    res = max(res, dfs(grid,i,j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;
        
        grid[x][y] = 0;
        return 1 + dfs(grid,x+1,y) + dfs(grid,x-1,y) + dfs(grid,x,y+1) + dfs(grid,x,y-1);
    }
    
};