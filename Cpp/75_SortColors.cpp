class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0, end = nums.size()-1;
        for(int i = 0; i <= end; ++i) {
            if(nums[i] == 0) {
                if(i != 0)
                    swap(nums[i], nums[begin]);
                ++begin;
            }
            else if(nums[i] == 2 && i < end) {
                swap(nums[i], nums[end]);
                --end;
                --i;
            }
        }
    }
};