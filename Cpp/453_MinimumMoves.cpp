class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int minnum = nums[0];
        int res = 0;
        for(int a : nums) {
            res += a - minnum;
        }
        return res;
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int minnum = INT_MAX;
        int res = 0;
        for(int a : nums) {
            res += a;
            if(a < minnum)
                minnum = a;
        }
        res -= (int)nums.size() * minnum;
        return res;
    }
};