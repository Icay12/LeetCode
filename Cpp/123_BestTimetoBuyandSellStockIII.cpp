//brute force solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        if(prices.size() <= 1)
            return maxprofit;
        for(int i = 0; i < prices.size(); ++i) {
            int iprofit = maxProfitOne(prices,0,i) + maxProfitOne(prices,i,(int)prices.size()-1);
            maxprofit = max(maxprofit, iprofit);
        }
        return maxprofit;
    }
    int maxProfitOne(vector<int>& prices, int begin, int end) {
        int minprice = prices[begin];
        int maxprofit = 0;
        for(int i = begin; i <= end; ++i) {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return maxprofit;
    }
};


// O(n) Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold2 = 0;
        int sold1 = 0;
        int buy1 = INT_MIN;
        int buy2 = INT_MIN;
        if(prices.size() <= 1)
            return sold2;
        for(int i = 0; i < prices.size(); ++i) {
            sold2 = max(sold2, prices[i] + buy2);
            buy2 = max(buy2, sold1 - prices[i]);
            sold1 = max(sold1, buy1 + prices[i]);
            buy1 = max(buy1, -prices[i]);
        }
        return sold2;
    }
};