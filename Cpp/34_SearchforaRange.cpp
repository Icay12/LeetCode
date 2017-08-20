class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.size() == 0)
            return res;
        if(nums.size() == 1) {
            if(nums[0] == target) {
                res[0] = res[1] = 0;
            }
            return res;
        }
        int last = nums.size() - 1, first = 0;

        while(first < last) {
            int mid = (first + last) / 2;
            if(nums[mid] < target) {
                first = mid + 1;
            }
            else {
                last = mid;
            }
        }
        if(nums[first] != target)
            return res;
        else
            res[0] = first;
        last = nums.size() - 1;
        first = 0;
        while(first < last) {
            int mid = (first + last) / 2 + 1;
            if(nums[mid] > target) {
                last = mid - 1;
            }
            else {
                first = mid;
            }
        }
        res[1] = first;
        return res;
    }
};