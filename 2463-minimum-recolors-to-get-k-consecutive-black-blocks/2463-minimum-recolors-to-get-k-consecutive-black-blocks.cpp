class Solution {
public:
    int countWhite(string s){
        int cnt=0;
        for(auto i:s)
            if(i=='W')
                cnt++;
        return cnt;
    }
    int minimumRecolors(string blocks, int k) {
        int ans=1e9;
        int n=blocks.size();
        for(int i=0;i<n;i++){
            if(i+k<=n)
                ans=min(ans,countWhite(blocks.substr(i,k)));
            else
                break;
        }
        return ans;
    }
};