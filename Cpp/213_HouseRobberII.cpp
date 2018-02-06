class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        return max(robline(nums,0,n-2), robline(nums,1,n-1));
    }
    
    int robline(vector<int>& nums, int begin, int end) {
        int odd = 0;
        int even = 0;
        for(int i = begin; i <= end; ++i) {
            if(i%2) {
                odd = max(odd+nums[i], even);
            }
            else {
                even = max(even+nums[i], odd);
            }
        }
        return max(odd,even);
    }
};