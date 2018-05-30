class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i; j >= 0; --j) {
                if(i == j)
                    dp[j][i] = nums[i];
                else {
                    int a = nums[i] + getsum(sum, j, i-1) - dp[j][i-1];
                    int b = nums[j] + getsum(sum, j+1, i) - dp[j+1][i];
                    dp[j][i] = max(a,b);
                }
            }
        }
        bool res = getsum(sum, 0, (int)nums.size()-1) - dp[0][(int)nums.size()-1] > dp[0][(int)nums.size()-1] ? false : true;
        return res;
    }
    
    int getsum(vector<int>& sum, int i, int j) {
        if(i == 0)
            return sum[j];
        else
            return sum[j] - sum[i-1];
    }
};