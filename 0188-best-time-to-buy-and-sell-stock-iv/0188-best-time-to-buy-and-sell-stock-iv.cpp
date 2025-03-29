class Solution {
public:
    // int function(int ind, int buy, int cap, vector<int>& prices,
    //              vector<vector<vector<int>>> dp) {
    //     if (ind == prices.size() || cap == 0)
    //         return 0;
    //     if (dp[ind][buy][cap] != -1)
    //         return dp[ind][buy][cap];
    //     int profit = 0;
    //     if (buy) // buy (buy=1)
    //         profit =
    //             max(-prices[ind] + function(ind + 1, 0, cap, prices, dp),
    //                 function(ind + 1, 1, cap, prices, dp)); // max(buy,skip)

    //     else // sell (buy=0)
    //         profit =
    //             max(prices[ind] + function(ind + 1, 1, cap - 1, prices, dp),
    //                 function(ind + 1, 0, cap, prices, dp)); // max(sell,skip)
    //     return dp[ind][buy][cap] = profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // M-1 (Rec+ memo)
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // return function(0, 1, k, prices, dp);

        // M-2 - Tabulation -
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        for(int ind=0;ind<n;ind++){
            for(int buy=0;buy<=1;buy++)
                dp[ind][buy][0]=0;
        }
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=k;cap++)
                dp[n][buy][cap]=0;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) // buy (buy=1)
                        dp[ind][buy][cap] =
                            max(-prices[ind] + dp[ind + 1][0][cap],
                                dp[ind + 1][1][cap]); // max(buy,skip)
                    else // sell (buy=0)
                        dp[ind][buy][cap] =
                            max(prices[ind] + dp[ind + 1][1][cap - 1],
                                dp[ind + 1][0][cap]); // max(sell, skip)
                }
            }
        }
        return dp[0][1][k];
    }
};