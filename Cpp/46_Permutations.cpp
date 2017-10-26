class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recursiveFunc(result, nums, 0);
        return result;
    }
    void recursiveFunc(vector<vector<int>>& result, vector<int>& nums, int begin) {
        if(begin >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            recursiveFunc(result, nums, begin + 1);
            swap(nums[begin], nums[i]);
        }
            
    }
};
