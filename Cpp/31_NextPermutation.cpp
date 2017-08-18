class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        int i, len = nums.size();
        for(i = len - 2; i >= 0; --i) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        if(i < 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j;
        for(j = len - 1; j > i; --j) {
            if(nums[j] > nums[i]) {
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};
