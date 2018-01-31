//word1: [0,...,m-1]
//word2: [0,...,n-1]
//dp[m][0] = m
//dp[0][n] = n
//no change: dp[m][n] = dp[m-1][n-1]  when word1[m-1] == word2[n-1] (consider the new character)
//insert: dp[m][n] = dp[m][n-1] + 1;
//delete: dp[m][n] = dp[m-1][n] + 1;
//replace: dp[m][n] = dp[m-1][n-1] + 1;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = word1.length();
        int j = word2.length();
        vector<vector<int>> dp(i+1, vector<int>(j+1,0));
        for(int m = 0; m <= i; ++m) {
            for(int n = 0; n <= j; ++n) {
                if(n == 0) {
                    dp[m][n] = m;
                }
                else if(m == 0) {
                    dp[m][n] = n;
                }
                else if(word1[m-1] == word2[n-1]) {
                    dp[m][n] = dp[m-1][n-1];
                }
                else {
                    dp[m][n] = min(min(dp[m][n-1],dp[m-1][n]),dp[m-1][n-1]) + 1;
                }
            }
        }
        return dp[i][j];
    }
};



//O(n) space solution

//word1: [0,...,m-1]
//word2: [0,...,n-1]
//dp[m][0] = m
//dp[0][n] = n
//no change: dp[m][n] = dp[m-1][n-1]  when word1[m-1] == word2[n-1] (consider the new character)
//insert: dp[m][n] = dp[m][n-1] + 1;
//delete: dp[m][n] = dp[m-1][n] + 1;
//replace: dp[m][n] = dp[m-1][n-1] + 1;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = word1.length();
        int j = word2.length();
        vector<int> dp(j+1);
        for(int k = 0; k < j + 1; ++k) {
            dp[k] = k;
        }
        int pre, tmp;
        for(int m = 1; m <= i; ++m) {
            pre = dp[0];
            dp[0] = m;
            for(int n = 1; n <= j; ++n) {
                int tmp = dp[n];
                if(word1[m-1] == word2[n-1]) {
                    dp[n] = pre;
                }
                else {
                    dp[n] = min(min(dp[n-1],dp[n]),pre) + 1;
                }
                pre = tmp;
            }
        }
        return dp[j];
    }
};