class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> len(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        
        int l = nums.size();
        int maxlen = 0;
        int maxindex = 0;
        for(int i = l-1; i >= 0; --i) {
            for(int j = i; j < l; ++j) {
                if(nums[j] % nums[i] == 0 && len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    parent[i] = j;
                    if(maxlen < len[i]) {
                        maxlen = len[i];
                        maxindex = i;
                    }
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < maxlen; ++i) {
            res.push_back(nums[maxindex]);
            maxindex = parent[maxindex];
        }
        return res;
    }
};