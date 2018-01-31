//1,1,1,1,1
//1,3,3
//3,3,1,3
//1,2,2,1

class Solution {
public:
    int findMin(vector<int>& nums) {
//         if(nums.size() == 1)
//             return nums[0];
        int begin = 0, end = (int)nums.size() - 1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(nums[mid] > nums[end]) {
                begin = mid + 1;
            }
            else if(mid == 0 || nums[mid-1] > nums[mid]) {
                return nums[mid];
            }
            else if(mid != end && nums[mid] == nums[end]){
                end -= 1;
            }
            else {
                end = mid - 1;
            }
        }
        return nums[begin];
    }
};