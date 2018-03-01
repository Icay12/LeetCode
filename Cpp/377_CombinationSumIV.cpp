// dp method
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> com(target+1,0);
        com[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i >= nums[j]) {
                    com[i] += com[i - nums[j]];
                }
            }
        }
        return com[target];
    }
    
};


// recursive method
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(target >= nums[i]) {
                res += combinationSum4(nums, target-nums[i]);
            }
        }
        return res;
    }
    
};