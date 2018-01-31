class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = (int)nums.size()-1;
        // if(end == 0)
        //     return nums[0];
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(nums[mid] > nums[end])
                begin = mid + 1;
            else if( mid == 0 || nums[mid-1] > nums[mid]) {
                return nums[mid];
            }
            else {
                end = mid - 1;
            }
                
        }
        return nums[begin];
    }
};