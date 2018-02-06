class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int> dp(matrix[0].size(), 0);
        int maxSide = 0;
        for(int i = 0; i < matrix[0].size(); ++i) {
            dp[i] = matrix[0][i] - '0';
            maxSide = max(maxSide, dp[i]);
        } 
        
        for(int i = 1; i < matrix.size(); ++i) {
            int pre = dp[0];
            dp[0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[0]);
            for(int j = 1; j < matrix[0].size(); ++j) {
                int tmp = dp[j];
                if(matrix[i][j] == '0')
                    dp[j] = 0;
                else {
                    dp[j] = min(dp[j-1],min(dp[j],pre)) + 1;
                }
                pre = tmp;
                maxSide = max(maxSide, dp[j]);
            }
        }
        return maxSide*maxSide;
    }
};