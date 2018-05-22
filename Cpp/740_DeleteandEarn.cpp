class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int take = 0, skip = 0;
        int take_i = 0, skip_i = 0;
        unordered_map<int, int> bucket;
        for(int i = 0; i < nums.size(); ++i) {
            bucket[nums[i]]+=nums[i];
        }
        for(int i = 0; i < 10001; ++i) {
            take_i = skip + bucket[i];
            skip_i = max(take, skip);
            take = take_i;
            skip = skip_i;
            // cout << take << " " << skip << endl;
        }
        return max(take, skip);
    }
};