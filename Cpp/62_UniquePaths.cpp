class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(n,vector<int>(m,1));
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[n-1][m-1];
    }
};