class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m != 0 ? grid[0].size() : 0;
        if(m == 0 || n == 0)
            return 0;
        int rowEnemies = 0;
        int res = 0;
        vector<int> colEnemies(n, 0);
        
        for(int i = 0; i < m; ++i) {
            rowEnemies = 0;
            for(int j = 0; j < n; ++j) {
                //first position in a row or a wall
                //update rowEnemies
                if(j == 0 || grid[i][j] == 'W') {
                    rowEnemies = 0;
                    int k = (grid[i][j] == 'W')? j+1 : j;
                    for(; k < n; ++k) {
                        if(grid[i][k] == 'W') {
                            break;
                        }
                        else if(grid[i][k] == 'E') {
                            rowEnemies++;
                        }
                    }
                }
                //first position in a col or a wall
                //update colEnemies
                if(i == 0 || grid[i][j] == 'W') {
                    colEnemies[j] = 0;
                    int k = (grid[i][j] == 'W')? i+1 : i;
                    for(; k < m; ++k) {
                        if(grid[k][j] == 'W') {
                            break;
                        }
                        else if(grid[k][j] == 'E') {
                            colEnemies[j]++;
                        }
                    }
                }
                
                // if can put a bomb
                if(grid[i][j] == '0') {
                    res = max(rowEnemies+colEnemies[j], res);
                }
            }
        }
        
        return res;
    }
};