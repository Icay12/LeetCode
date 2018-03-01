class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return (int)nums.size();
        
        int result = 1;
        int k = 1;
        
        while(k < nums.size() && nums[k] == nums[k-1])
            ++k;
        if(k >= nums.size())
            return 1;
        vector<int> res;
        res.push_back(nums[0]);
        res.push_back(nums[k]);
        bool issmaller = (nums[k] < nums[0]);
        for(k = k+1; k < nums.size(); ++k) {
            if(nums[k] > res[result]) {
                if(issmaller) {
                    res.push_back(nums[k]);
                    result+=1;
                    issmaller = !issmaller;
                }
                else {
                    res[result] = max(res[result], nums[k]);
                }
                
            }
            if(nums[k] < nums[k-1]) {
                if(!issmaller) {
                    res.push_back(nums[k]);
                    result+=1;
                    issmaller = !issmaller;
                }
                else {
                    res[result] = min(res[result], nums[k]);
                }
            }
        }
        return result+1;
        
    }
};