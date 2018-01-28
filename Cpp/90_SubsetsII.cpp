class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        res.push_back(sub);
        int len;
        int begin;
        for(int i = 0; i < nums.size(); ++i) {
            if(i != 0 && nums[i] == nums[i-1])
                begin = len;
            else
                begin = 0;
            len = res.size();
            for(int j = begin; j < len; ++j) {
                sub = res[j];
                sub.push_back(nums[i]);
                res.push_back(sub);
            }
        }
        return res;
    }
};