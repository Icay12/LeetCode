class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sold = 0;
        int buy = INT_MIN;
        for(int i = 0; i < prices.size(); ++i) {
            sold = max(buy + prices[i], sold);
            buy = max(sold - fee - prices[i], buy);
        }
        return sold;
    }
};