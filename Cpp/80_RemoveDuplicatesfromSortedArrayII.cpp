class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int point = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1]) {
                nums[point] = nums[i];
                ++point;
                cnt = 1;
            }
            else if(nums[i] == nums[i-1] && cnt > 0) {
                nums[point] = nums[i];
                ++point;
                --cnt;
            }
        }
        return point;
    }
};