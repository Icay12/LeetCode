class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 || n == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0)
                    continue;
                for(int k = j+1; k < n; ++k) {
                    if(grid[i][k] == 0)
                        continue;
                    res += dp[j][k];
                    dp[j][k]++;
                }
            }
        }
        return res;
     }
};