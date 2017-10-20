class Solution {
public:
    int jump(vector<int>& nums) {
        int currentEnd = 0;
        int currentFar = 0;
        int jumps = 0;
        for(int i = 0; i < nums.size()-1; ++i) {
            currentFar = max(currentFar, i+nums[i]);
            if(currentFar >= nums.size()-1) {
                jumps += 1;
                break;
            }
            if(i == currentEnd) {
                jumps += 1;
                currentEnd = currentFar;
            }            
        }
        return jumps;
    }
};