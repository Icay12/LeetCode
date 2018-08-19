class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> debt;
        for(auto a : transactions) {
            debt[a[0]] += a[2];
            debt[a[1]] -= a[2];
        }
        
        vector<int> v;
        for(auto p : debt) {
            if(p.second != 0)
                v.push_back(p.second);
        }
        
        return dfs(v, 0);
    }
    
    int dfs(vector<int>& v, int start) {
        while(start < v.size() && v[start] == 0) {
            start++;
        }
        if(start == v.size())
            return 0;
        int res = INT_MAX;
        for(int i = start + 1; i < v.size(); ++i) {
            if(v[start]*v[i] < 0) {
                v[i] += v[start];
                res = min(res, dfs(v, start+1)+1);
                v[i] -= v[start];
            }
        }
        return res;
    }
    
    
};