class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int begin = 0, end = 1;
        int res = 1;
        while(end < nums.size()) {
            if(nums[end] > nums[end-1])
                end++;
            else {
                res = max(res, end - begin);
                begin = end;
                end++;
            }
        }
        res = max(res, end - begin);
        return res;
    }
};