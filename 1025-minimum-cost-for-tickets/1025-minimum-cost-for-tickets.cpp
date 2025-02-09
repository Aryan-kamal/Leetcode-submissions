class Solution {
public:
    int function(vector<int>& days, vector<int>& cost,int n,int i,vector<int>&dp){
        if(i>=n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int cost_1=cost[0]+function(days,cost,n,i+1,dp);

        int j=i;
        int max_day=days[i]+7;
        while(j<n&&days[j]<max_day)
            j++;
        int cost_7=cost[1]+function(days,cost,n,j,dp);

        j=i;
        max_day=days[i]+30;
        while(j<n&&days[j]<max_day)
            j++;
        int cost_30=cost[2]+function(days,cost,n,j,dp);

        return dp[i]=min({cost_1,cost_7,cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(366,-1);
        return function(days,costs,n,0,dp);
    }
};