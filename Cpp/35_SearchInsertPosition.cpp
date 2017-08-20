//there is better solution, just use simple binary search.
//try to improve it in the Java version
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1) {
            if(nums[0] < target)
                return 1;
            else
                return 0;
        }
        if(target > nums[nums.size()-1]) {
            return nums.size();
        }
        if(target < nums[0]) {
            return 0;
        }
        int first = 0, last = nums.size() - 1;
        while(first <= last) {
            int mid = (first + last) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target && nums[mid+1] > target) {
                return mid+1;
            }
            else if(nums[mid] < target){
                first = mid + 1;
            }
            else {
                last = mid;
            }
        }
    }
};