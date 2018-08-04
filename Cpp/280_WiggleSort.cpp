class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) {
            // odd position, large
            if(i % 2 && nums[i] < nums[i-1])
                swap(nums[i], nums[i-1]);
            if( !(i%2) && nums[i] > nums[i-1])
                swap(nums[i], nums[i-1]);
            
        }
    }
};