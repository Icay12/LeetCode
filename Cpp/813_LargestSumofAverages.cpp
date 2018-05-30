class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.size() == 0)
            return 0;
        vector<vector<double>> dp(A.size(), vector<double>(K+1, 0));
        vector<double> sum(A.size(), 0);
        int len = A.size();

        dp[0][1] = A[0];
        sum[0] = A[0];
        for(int i = 1; i < len; ++i) {
            sum[i] = sum[i-1] + A[i];
            dp[i][1] = sum[i]/(i+1);
        }
        if(K == 1)
            return dp[len-1][1]; //sum of all the elements

        for(int k = 2; k <= K; ++k) {
            for(int i = k-1; i < len; ++i) {
                double maxvalue = 0;
                for(int p = k-2; p < i; ++p) {
                    double tmp = dp[p][k-1] + (sum[i] - sum[p])/(i-p);
                    maxvalue = max(maxvalue, tmp);
                }
                dp[i][k] = maxvalue;
            }
        }

        return dp[len-1][K];

    }

};