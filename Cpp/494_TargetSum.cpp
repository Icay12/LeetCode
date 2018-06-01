
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if((sum + S) & 1)
            return 0;
        if(sum < S)
            return 0;
        return subsum(nums, (sum+S)>>1);
    }
    
    int subsum(vector<int>& nums, int sum) {
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(int num : nums) {
            for(int i = sum; i >= num; --i) {
                dp[i] += dp[i-num];
            }
        }
        return dp[sum];
    }
};