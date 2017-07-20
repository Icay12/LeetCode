class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        //https://discuss.leetcode.com/topic/82514/runtime-error-message-reference-binding-to-null-pointer-of-type-struct-value_type/3
        //C++'s vector's size() returns size_type which is unsigned. Hence, if size() returns 0, doing -1 would cause an overflow. One method is to first convert size_type into int before doing -1.
        for(int i = 0; i < (int)nums.size()-2; ++i) {

            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = 0 - nums[i];
            int j = i + 1, k = (int)nums.size() - 1;
            while(j < k) {
                if(nums[j] + nums[k] == target) {
                    vector<int> triplet(3,0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[k];
                    result.push_back(triplet);
                    ++j;
                    --k;
                    while(j < k && nums[j] == nums[j-1]) ++j;
                    while(j < k && nums[k] == nums[k+1]) --k;
                }
                else if(nums[j] + nums[k] > target) {
                    --k;
                }
                else {
                    ++j;
                }
            }
        }
        return result;

    }
};