class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        if(k > n || k == 0)
            return res;
        vector<int> tmp;
        dfs(res, tmp, n, 1, k);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& tmp, int n, int pos, int k) {
        if(k == 0) {
            res.push_back(tmp);
            return;
        }
        
        for(int i = pos; i <= n - k + 1; ++i) {
            tmp.push_back(i);
            dfs(res, tmp, n, i+1, k-1);
            tmp.pop_back();
        }    
        
        return;
    }
};