class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int a=0,cnt=0;
        for(int i=0;i<n;i++){
            if(a>=m)
                break;
            if(g[i]<=s[a])
                cnt++;
            else
                i--;
            a++;
        }
        return cnt;
    }
};