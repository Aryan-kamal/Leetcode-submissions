class Solution {
public:
    // Memo -
    int function(int ind, int buy, vector<int>& prices,
                 vector<vector<int>>& dp) {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) // buy (buy=1)
            profit = max(-prices[ind] + function(ind + 1, 0, prices, dp),
                         function(ind + 1, 1, prices, dp)); // max(buy,skip)

        else // sell (buy=0)
            profit = max(prices[ind] + function(ind + 1, 1, prices, dp),
                         function(ind + 1, 0, prices, dp)); // max(sell, skip)
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // M-1- Rec+ memo
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return function(0, 1, prices, dp);

        // M-2 - Tabulation
        vector<vector<long>> dp(n + 1, vector<long>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        long profit;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                if (buy)
                    profit = max(dp[ind + 1][1], -prices[ind] + dp[ind + 1][0]);
                else
                    profit = max(dp[ind + 1][0], prices[ind] + dp[ind + 1][1]);
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];

        // M-3 -
        // int profit = 0;
        // for(int i=1;i<n;i++){
        //     if(prices[i] > prices[i-1])
        //     profit += prices[i]-prices[i-1];
        // }
        // return profit;
    }
};