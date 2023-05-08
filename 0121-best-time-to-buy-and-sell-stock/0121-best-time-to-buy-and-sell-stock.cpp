class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniBuy = prices[0], maxprofit = INT_MIN;
        for(int i =0; i < prices.size(); i++)
        {
            int cost = prices[i] - miniBuy;
            maxprofit = max(maxprofit, cost);
            miniBuy = min(miniBuy, prices[i]);
        }
        
        return maxprofit;        
    }
};