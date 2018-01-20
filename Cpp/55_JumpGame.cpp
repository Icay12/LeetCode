class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        if(nums.size() == 0)
            return false;
        int currentFar = 0;
        // int currentEnd = 0;
        int i = 0;
        while(i < nums.size()) {
            currentFar = max(currentFar, i + nums[i]);
            if(currentFar == i)
                return false;
            if(currentFar >= nums.size()-1)
                return true;
            i++;
        }
    }
};