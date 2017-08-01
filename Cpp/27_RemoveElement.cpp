class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int n : nums) {
            if(n != val) {
                nums[cnt++] = n;
            }
        }
        return cnt;
    }
};