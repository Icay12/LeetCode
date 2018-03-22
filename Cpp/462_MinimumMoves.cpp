class Solution {
public:
    int minMoves2(vector<int>& nums) {       
        sort(nums.begin(), nums.end());
        int medianIndex = nums.size() / 2;
        
        int result = 0;
        for(int a : nums) {
            result += abs(a - nums[medianIndex]);
        }
        
        return result;
    }
};
