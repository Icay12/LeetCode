class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if(sum & 1)
            return false;
        int target = sum >> 1;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(int num : nums) {
            for(int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};