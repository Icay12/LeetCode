class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int i;
        for(i = 0; i < nums.size(); ++i) {
            if(nums[i] == i +1)
                continue;
            while(nums[i] > 0 && nums[i] < nums.size() && nums[i]!=nums[nums[i]-1]) {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1) {
                return i+1;
            }
        }
        return i+1;
    }
};