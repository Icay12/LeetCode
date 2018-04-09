class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxV = 0;
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int x = DFS(matrix,i,j,visited);
                maxV = max(maxV, x);
            }
        }
        return maxV;
    }
    int DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& visited) {
        if (visited[i][j] != 0) 
            return visited[i][j];
        int maxV = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        if(i+1<m && matrix[i][j] < matrix[i+1][j])
            maxV = max(maxV, DFS(matrix, i+1, j, visited)+1);
        if(i-1>=0 && matrix[i][j] < matrix[i-1][j])
            maxV = max(maxV, DFS(matrix, i-1, j, visited)+1);
        if(j+1<n && matrix[i][j] < matrix[i][j+1])
            maxV = max(maxV, DFS(matrix, i, j+1, visited)+1);
        if(j-1>=0 && matrix[i][j] < matrix[i][j-1])
            maxV = max(maxV, DFS(matrix, i, j-1, visited)+1);
        visited[i][j] = maxV;
        return maxV;
        
    }
};