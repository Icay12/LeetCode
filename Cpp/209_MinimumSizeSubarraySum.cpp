class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int begin = 0;
        int end = 0;
        int minlen = INT_MAX;
        long long sum = nums[0];
        while(end < nums.size() && begin <= end) {
            if(sum < s) {
                end += 1;
                if(end < nums.size())
                    sum += nums[end];
                else
                    break;
            }
            else {
                minlen = min(minlen, end-begin+1);      
                if(begin != end)
                    sum -= nums[begin];
                else
                    break;
                begin += 1;
            }
                
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};