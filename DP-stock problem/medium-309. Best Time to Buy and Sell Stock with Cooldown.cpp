class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy (prices.size(), 0); // 目前持有股票
        vector<int> sell (prices.size(), 0); // 目前沒有股票
        
        if (prices.size() == 1) return 0;
        if (prices.size() == 2) return (prices[1] > prices[0]) ? prices[1]-prices[0] : 0;
        
        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(sell[0], buy[0]+prices[1]);
        
        for (int i = 2; i < prices.size(); i++) {
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
        }
        
        return sell[prices.size()-1];
    }
};