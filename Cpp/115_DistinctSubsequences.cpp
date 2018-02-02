class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() == 0 && t.size() == 0)
            return 1;
        if(s.size() == 0)
            return 0;
        int pre = 1;
        vector<int> dp(s.size()+1, 1);
        dp[0] = 0;
        for(int i = 0; i < t.size(); ++i) {   
            if(i == 0)
                pre = 1;
            else
                pre = 0;
            for(int j = 1; j <= s.size(); ++j) {
                int tmp = dp[j];
                dp[j] = s[j-1] == t[i]? pre + dp[j-1] : dp[j-1];
                pre = tmp;
                // cout << dp[j] << " ";
            }
            // cout << endl;
        }
        return dp[(int)s.size()];
    }
};