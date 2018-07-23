class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int sum = 0;
        int result = 0;
        hash[0] = -1;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(hash.count(sum) == 0)
                hash[sum] = i;
            if(hash.count(sum-k) != 0) {
                result = max(result, i - hash[sum-k]);
            }
        }
        return result;
    }
};