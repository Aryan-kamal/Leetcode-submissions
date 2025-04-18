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
        // M-1 (Recursion)
        return rec(1,"1",n);
    }
};

// M-2 -
// string countAndSay(int n) {
//     if (n == 1) return "1";
//     string temp = "1";
//     for (int i = 2; i <= n; i++) {
//         string curr = "";
//         int count = 1;
//         for (int j = 1; j <= temp.size(); j++) {
//             if (j < temp.size() && temp[j] == temp[j - 1])
//                 count++;
//             else {
//                 curr += to_string(count);
//                 curr += temp[j - 1];
//                 count = 1;
//             }
//         }

//         temp = curr;
//     }
//     return temp;
// }