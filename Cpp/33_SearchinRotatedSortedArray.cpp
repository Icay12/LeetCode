class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) 
            return -1;
        int first = 0, last = (int)nums.size() - 1;
        
        while(first <= last) {
            int middle = (first + last)/2;
            if(nums[middle] == target) {
                return middle;
            }
            //later array is ascending
            if(nums[last] > nums[middle]) {
                //search behind
                if(target > nums[middle] && target <= nums[last]) {
                    first = middle + 1;
                }
                //search front
                else {
                    last = middle - 1;
                }
            }
            //former array is ascending
            else {
                //search front
                if(target < nums[middle] && target >= nums[first]) {
                    last = middle -1;
                }
                //search behind
                else {
                    first = middle + 1;
                }
            }
            
        }
        return -1;
    }
};