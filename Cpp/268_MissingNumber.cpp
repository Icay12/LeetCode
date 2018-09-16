class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum =  (1 + n) * n / 2;
        int a = 0;
        for(int i : nums) {
            a += i;
        }
        return sum - a;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            a = a ^ i;
            a = a ^ nums[i];
        }
        return a;
    }
};