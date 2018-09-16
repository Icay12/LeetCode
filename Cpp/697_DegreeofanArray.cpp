class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]].push_back(i);
        }
        
        int degree = 0;
        for(auto p : hash) {
            degree = max(degree, (int)p.second.size());
        }
        
        int res = nums.size();
        for(auto p : hash) {
            if(p.second.size() == degree) {
                int len = p.second.back() - p.second.front() + 1;
                res = min(len, res);
            }
        }
        
        return res;
    }
};