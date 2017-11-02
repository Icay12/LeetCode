class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        permuteRecursion(result, nums, 0);
        return result;
    }
    void permuteRecursion(vector<vector<int>>& result, vector<int> nums, int begin) {
        if(begin == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); ++i) {
            if(i != begin && nums[i] == nums[begin]) {
                continue;
            }
            swap(nums[begin], nums[i]);
            permuteRecursion(result, nums, begin + 1);
        }
    }
};