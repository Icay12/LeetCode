class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int begin = 0, end = 0;
        
        int n = nums.size();
        
        int cnt = 0;
        long curProduct = 1;
        int res = 0;
        while(begin <= end && end < n) {
            curProduct *= nums[end];
            while(begin <= end && curProduct >= k) {
                res += end - begin;  
                curProduct /= nums[begin];
                begin++;
            }
            end++;
        }
        for(int i = end - begin; i > 0; --i) {
            res += i;
        }
        return res;
    }
};