class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        if(nums.size() == 2)
            return abs(nums[0]-nums[1]);
        int n = nums.size();
        int minnum = nums[0];
        int maxnum = nums[0];
        for(int i = 1; i < n; ++i) {
            minnum = min(minnum, nums[i]);
            maxnum = max(maxnum, nums[i]);
        }
        int len = maxnum - minnum;
        if(len <= 1)
            return len;
        vector<int> gapmax(n, INT_MIN);
        vector<int> gapmin(n, INT_MAX);
        
        for(int i = 0; i < n; ++i) {
            int index = (double)( nums[i] - minnum )  / len * ( n - 1 ); // important
            gapmax[index] = max(gapmax[index], nums[i]);
            gapmin[index] = min(gapmin[index], nums[i]);
        }
        int res = 0;
        int pre = gapmax[0];
        for(int i = 1; i < n; ++i) {
            if(gapmax[i] == INT_MIN)
                continue;
            res = max(res, gapmin[i]-pre);
            pre = gapmax[i];
        }
        return res;
        
    }
};
