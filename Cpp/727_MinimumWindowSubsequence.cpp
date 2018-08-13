class Solution {
public:
    string minWindow(string S, string T) {
        int pt = 0;
        int ps = 0;
        
        string res = "";
        
        for(int i = 0; i < S.length(); ++i) {
            vector<int> dp(S.length(), 0);
            for(int j = i; j < S.length(); ++j) {
                if(j == i && S[i] == T[0]) {
                    dp[j] = 1;
                }
                else if(j != i) {
                    if(dp[j-1] != T.length() && S[j] == T[dp[j-1]]) 
                        dp[j] = 1 + dp[j-1];
                    else
                        dp[j] = dp[j-1];
                }
                if(dp[j] == T.size()) {
                    if(res.length() == 0 || j-i+1 < res.length()) {
                        res = S.substr(i, j-i+1);
                        if(res.length() == T.length())
                            break;
                    }
                }
                // cout << dp[i][j]<< " ";
            }
            // cout << endl;
        }
        return res;
        
    }
};



//O(mn)

class Solution {
public:
    string minWindow(string S, string T) {

        
        string res = "";
        vector<vector<int>> dp(T.length()+1, vector<int>(S.length()+1,-1));
        
            
            for(int j = 0; j <= S.length(); ++j) {
                dp[0][j] = j;
            }
        
            // for(int i = 0; i <= T.length(); ++i) {
            //     dp[i][0] = 0;
            // }
        
        for(int i = 1; i <= T.length(); ++i) {
            
            for(int j = 1; j <= S.length(); ++j) {
                if(T[i-1] == S[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
                // cout << dp[i][j]<< " ";
            }
            // cout << endl;
        }
        int minLen = INT_MAX;                    
                    
        for(int j = T.length(); j <= S.length(); ++j)  {
            if(dp[T.length()][j] != -1 && j - dp[T.length()][j] < minLen) {
                minLen = j - dp[T.length()][j];
                res = S.substr(dp[T.length()][j], minLen);
            }
        }
        return res;
        
    }
};