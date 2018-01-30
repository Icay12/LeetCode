class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        // vector<int> difference;
        int max = 0;
        for(int i = 0; i < prices.size()-1; ++i) {
            // difference.push_back(prices[i+1]-prices[i]);
            if(prices[i+1]-prices[i] > 0)
                max += prices[i+1]-prices[i];
        }
        return max;
    }
};