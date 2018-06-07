class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.length() == 0)
            return res;
        vector<string> solu;
        dfs(res, solu, s, 0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& solu, string s, int begin) {
        if(begin == s.length())
            res.push_back(solu);
        
        for(int i = begin; i < s.length(); ++i) {
            string sub = s.substr(begin, i-begin+1);
            if(isPalindrome(sub)) {
                solu.push_back(sub);
                dfs(res, solu, s, i+1);
                solu.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int len = s.length();
        int mid1 = (len-1)/2;
        int mid2 = len/2;
        while(mid1 >= 0) {
            if(s[mid1] != s[mid2])
                return false;
            mid1--;
            mid2++;
        }
        return true;
    }
};