class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a = 0;
        for(int n : nums) {
            a ^= n;
        }
        return a;
    }
};