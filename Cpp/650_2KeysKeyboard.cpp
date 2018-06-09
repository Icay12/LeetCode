class Solution {
public:
    int minSteps(int n) {
        if(n <= 1)
            return 0;
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 0;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= sqrt(i); ++j) {
                if(i % j == 0) {
                    dp[i] = min(i/j+dp[j], dp[i]);
                    dp[i] = min(j + dp[i/j], dp[i]);
                }
            }
        }
        if(dp[n] == INT_MAX)
            return n;
        return dp[n];
    }
};