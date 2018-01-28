class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int front = 0;
        int back = nums.size() - 1;
        while(front <= back) {
            int mid = (front + back) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] > nums[back]) {  //not > nums[front], because we use (front + back)/2,
                if(target >= nums[front] && target < nums[mid]) {
                    back = mid - 1;
                }
                else {
                    front = mid + 1;
                }
            }
            else if(nums[mid] < nums[back]) {
                if(target > nums[mid] && target <= nums[back]) {
                    front = mid + 1;
                }
                else {
                    back = mid - 1;
                }
            }
            else {
                --back;
            }
        }
        return false;
    }
};