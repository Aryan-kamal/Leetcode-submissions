class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string wd="";
        for(int i=0;i<n;i++){
            wd=wd + to_string((s[i]-'a')+1);
        }
        for(int i=1;i<=k;i++)
        {
            int sum=0;
            for(int j=0;j<wd.length();j++)
            {
                sum+=(wd[j]-'0');
            }
            wd=to_string(sum);
        }
        return stoi(wd);
    }
};