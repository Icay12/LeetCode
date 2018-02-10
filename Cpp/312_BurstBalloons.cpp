class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len+2, vector<int>(len+2,0));
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        for(int l = 1; l <= len; ++l) {
            for(int i = 1; i <= len - l + 1; ++i) {
                int maxCoin = 0;
                for(int j = i; j <= i+l-1; ++j) {
                    int coin = dp[i][j-1] + dp[j+1][i+l-1];
                    coin += nums[i-1]*nums[j]*nums[i+l-1+1];
                    maxCoin = max(maxCoin, coin);
                }
                dp[i][i+l-1] = maxCoin;
                // cout << maxCoin << endl;
            }
        }
        return dp[1][len];                       
    }
};