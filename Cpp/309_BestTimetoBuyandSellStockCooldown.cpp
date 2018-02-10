class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0, prebuy = INT_MIN, presell = 0;
        for(int price : prices) {
            buy = max(presell-price, prebuy);
            presell = sell;
            sell = max(prebuy+price, presell);
            prebuy = buy;
        }
        return sell;
    }
};