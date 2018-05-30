//bit
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bit(1);
        int sum = 0;
        for(int num : nums) {
            sum += num;
            bit |= (bit << num);
        }
        return !(sum&1) && bit[sum >> 1];
    }
};


//DP
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