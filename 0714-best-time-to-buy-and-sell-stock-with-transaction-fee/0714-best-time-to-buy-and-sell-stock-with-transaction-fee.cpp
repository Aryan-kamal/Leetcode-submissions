class Solution {
public:
    int function(int ind, int buy, vector<int>& prices,
                 vector<vector<int>>& dp,int fee) {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) // buy (buy=1)
            profit = max(-prices[ind] + function(ind + 1, 0, prices, dp,fee),
                         function(ind + 1, 1, prices, dp,fee)); // max(buy,skip)

        else // sell (buy=0)
            profit = max(prices[ind] - fee + function(ind + 1, 1, prices, dp,fee),
                         function(ind + 1, 0, prices, dp,fee)); // max(sell, skip)
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return function(0, 1, prices, dp,fee);
    }
};