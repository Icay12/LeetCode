class Solution {
public:
    int checkRecord(int n) {
        vector<long long> dp(6,0);
        vector<long long> predp(6,0);
        int m = 1000000007;
        dp[0] = 1;
        dp[1] = 1;
        dp[3] = 1;
        
        for(int i = 1; i < n; ++i) {
            predp = dp;
            dp[0] = (predp[0] + predp[1] + predp[2])%m;
            dp[1] = (predp[0])%m;
            dp[2] = (predp[1])%m;
            dp[3] = (predp[0] + predp[1] + predp[4] + predp[2] + predp[5] + predp[3])%m;
            dp[4] = (predp[3])%m;
            dp[5] = (predp[4])%m;
        }
        
        long long res = 0;
        for(int j = 0; j < 6; ++j) {
            res += dp[j];
        }

        return res % m;
    }
};