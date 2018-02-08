class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            int j = 1;
            while((i - j*j)>=0 ) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
                ++j;
            }
        }
        return dp[n];
    }
};