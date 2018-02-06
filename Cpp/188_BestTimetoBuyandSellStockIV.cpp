class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1 || k == 0)
            return 0;
        if(k > n/2)
            k = n/2;
        vector<int> buy(k, INT_MIN);
        vector<int> sold(k, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = k-1; j >= 0; --j) {
                if(j > 0) {
                    sold[j] = max(sold[j], buy[j]+prices[i]);
                    buy[j] = max(buy[j], sold[j-1]-prices[i]);
                }
                else {
                    sold[j] = max(sold[j], buy[j]+prices[i]);
                    buy[j] = max(buy[j], -prices[i]);
                }
                
            }
        }
        return sold[k-1];
    }
};