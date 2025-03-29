class Solution {
public:
    // Similar to II, only change in sell condn 
    int function(int ind, int buy, vector<int>& prices,
                 vector<vector<int>>& dp) {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) // buy (buy=1)
            profit = max(-prices[ind] + function(ind + 1, 0, prices, dp),
                         function(ind + 1, 1, prices, dp)); // max(buy,skip)

        else // sell (buy=0)
            profit = max(prices[ind] + function(ind + 2, 1, prices, dp),
                         function(ind + 1, 0, prices, dp)); // max(sell, skip)
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return function(0, 1, prices, dp);
    }
};