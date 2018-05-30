class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        vector<unordered_map<int, int>> dp(A.size());
        int res = 0;
        
        for(int i = 1; i < A.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                long long dis = (long long)A[i] - (long long)A[j];
                if(dis > INT_MAX || dis < INT_MIN)
                    continue;
                
                int dif = (int)dis;
                dp[i][dif] += 1;
                if(dp[j].find(dif) != dp[j].end()) {
                    dp[i][dif] += dp[j][dif];
                    res += dp[j][dif];
                }
                
            }
            
            
        }
        return res;
    }
};

