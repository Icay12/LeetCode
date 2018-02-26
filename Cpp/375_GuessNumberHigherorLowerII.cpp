class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        return getMoney(dp, 1, n);
    }
    int getMoney(vector<vector<int>>& dp, int begin, int end) {
        if(begin >= end)
            return 0;
        if(dp[begin][end] != 0)
            return dp[begin][end];
        int res = INT_MAX;
        for(int i = begin; i <= end; ++i ) {
            int ires = i + max(getMoney(dp,begin,i-1), getMoney(dp,i+1,end));
            res = min(res,ires);
        }
        dp[begin][end] = res;
        return res;
    }
};