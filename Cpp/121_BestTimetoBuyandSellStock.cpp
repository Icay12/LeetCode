class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int maxprofit = 0;
        int minprice = prices[0];
        for(int i = 0; i < prices.size(); ++i) {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return maxprofit;
    }
};