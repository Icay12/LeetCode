class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int totalSum = 0;
        for(int i = 0; i < A.size(); ++i) {
            totalSum += A[i];
        }
        
        bool exist = false;
        int m = (int)A.size() / 2;
        int n = (int)A.size();
        for(int i = 0; i < m; ++i) {
            if(totalSum*i % n == 0) {
                exist = true;
            }   
        }
        
        if(!exist)
            return false;
        
        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);
        //choose j elements in k elements, calculate sum
        for(int a : A) {
            for(int i = m; i > 0; --i) {
                for(int b : dp[i-1])
                    dp[i].insert(b+a);
            }
        }        
        
        for(int i = 1; i <= m; ++i) {
            if(totalSum*i % n == 0 && dp[i].find(totalSum*i/n) != dp[].end())
                return true;
        }
        return false;
    }
};