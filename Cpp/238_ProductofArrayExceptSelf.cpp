class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() <= 1)
            return vector<int>();
        vector<int> res(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); ++i) {
            res[i] = nums[i-1]*res[i-1];
        }
        
        int right = nums[(int)nums.size()-1];
        
        for(int i = nums.size()-2; i >= 0; --i) {
            res[i] = res[i] * right;
            right *= nums[i];
        }
        
        return res;
        
        
    }
};