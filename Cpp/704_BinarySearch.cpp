class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        
        while(begin <= end) {
            int mid = begin + ((end-begin)>>1);
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                begin = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return -1;
    }
};