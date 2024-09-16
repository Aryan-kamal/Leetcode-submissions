class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int len=trust.size();
        for (int i=1;i<=n;i++)
        {
            int cnt=0,f=0;
            for(int j=0;j<len;j++)
            {
                if(trust[j][0]==i)
                {
                    f=1;
                    break;
                }     
                if(trust[j][1]==i)
                    cnt++;
            }
            if(cnt==n-1 && f==0)
                return i;
        }
        return -1;
    }
};