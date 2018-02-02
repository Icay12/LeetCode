class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> inDict(n+1, false);
        inDict[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(inDict[j]) {
                    string word = s.substr(j,i-j);
                    if( find(wordDict.begin(), wordDict.end(),word) != wordDict.end()) {
                        inDict[i] = true;
                        break;
                    }
                }
            }
        }
        return inDict[n];
    }
};