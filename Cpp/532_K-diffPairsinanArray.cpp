class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        unordered_map<int,int> visited;
        int res = 0;
        for(auto a : nums) {
            visited[a]++;
        }
        for(auto p : visited) {
            if(k == 0 && p.second > 1)
                res++;
            if(k != 0 && visited.count(p.first+k) != 0)
                res++;
        }
        return res;
    }
};