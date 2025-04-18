class Solution {
public:
    string rec(int a,string s,int n){
        if(a==n)
            return s;
        int len=s.size();
        string wd="";
        int l=0,r=0;
        while(l<len){
            int cnt=0;
            char ch=s[l];
            while(r < len && s[r] == ch)
            {
                cnt++;
                r++;
            }
            wd=wd+to_string(cnt)+ch;
            l=r;
        }   
        return rec(a+1,wd,n);
    }
    string countAndSay(int n) {
        return rec(1,"1",n);
    }
};