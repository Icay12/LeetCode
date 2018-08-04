class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> visited = vector<bool>(10, false);
        visited[0] = true;
        vector<vector<int>> skip = vector<vector<int>>(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        int res = 0;
        for(int i = m; i <= n; ++i) {
            res += dfs(visited, skip, 1, i-1) * 4; // 1, 3, 7, 9
            res += dfs(visited, skip, 2, i-1) * 4; // 2, 4, 6, 8
            res += dfs(visited, skip, 5, i-1); //5
        }
        return res;
    }
    
    int dfs(vector<bool>& visited, const vector<vector<int>> &skip, int cur, int remain) {
        if(visited[cur]) {
            return 0;
        }
        if(remain == 0)
            return 1;
        visited[cur] = true;
        int res = 0;
        for(int i = 1; i < 10; ++i) {
            if(visited[skip[cur][i]])
                res += dfs(visited, skip, i, remain - 1);
        }
        visited[cur] = false;
        return res;
    }
    
};