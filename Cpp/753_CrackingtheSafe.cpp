//dfs
class Solution {
public:
    string crackSafe(int n, int k) {
        string res = string(n, '0');
        unordered_set<string> visited;
        dfs(n, k, res, visited);
        return res;
    }
    
    bool dfs(int n, int k, string &res, unordered_set<string>& visited) {
        if(res.length() == pow(k, n) + n-1) {
            return true;
        }
        string ores = res;
        string prev = res.substr(res.size()-n+1);
        for(int i = k-1; i >= 0; --i) {
            string current = prev + to_string(i);
            if(visited.find(current) == visited.end()) {
                visited.insert(current);
                res+=to_string(i);
                if(dfs(n,k,res,visited))
                    return true;
                else {
                    res = ores;
                }
            }
        }
        return false;
    }
};

//directly


