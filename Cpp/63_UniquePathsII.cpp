class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n,1));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    if(obstacleGrid[0][0] == 1)
                        return 0;
                } 
                else if(i == 0)
                    paths[i][j] = paths[i][j-1]*(1-obstacleGrid[i][j]);
                else if(j == 0)
                    paths[i][j] = paths[i-1][j]*(1-obstacleGrid[i][j]);
                else
                    paths[i][j] = paths[i-1][j]*(1-obstacleGrid[i][j]) + paths[i][j-1]*(1-obstacleGrid[i][j]);
            }
        }
        return paths[m-1][n-1];
    }
};