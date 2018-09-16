class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, int> hashp;
        unordered_map<string, int> hashs;
        
        return dfs(hashp, hashs, pattern, str, 0, 0);
    }
    
    bool dfs(unordered_map<char, int> &hashp, unordered_map<string, int> &hashs, string pattern, string str, int p, int s) {
        if(p == pattern.length() && s == str.length()) {
            return true;
        }
        if(p == pattern.length() || s == str.length()) {
            return false;
        }
        
        for(int i = 1; i + s<= str.length(); ++i) {
            string word = str.substr(s, i);
            if(hashp[pattern[p]] == hashs[word]) {
                int tmp = hashp[pattern[p]];
                hashp[pattern[p]] = p+1 ;
                hashs[word] = p+1;
                if(dfs(hashp, hashs, pattern, str, p+1, s+i)) {
                    return true;
                }
                hashp[pattern[p]] = tmp ;
                hashs[word] = tmp;
            }
        }
        
        return false;
        
    }
};