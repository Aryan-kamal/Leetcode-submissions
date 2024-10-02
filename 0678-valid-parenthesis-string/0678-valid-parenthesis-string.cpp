class Solution {
public:
    // Recrsive fn --
    bool f(string s,int ind,int cnt){
        int n=s.size();
        if(cnt<0)
            return false;
        if(ind==n)
            return cnt==0;
        if(s[ind]=='(')
            return f(s,ind+1,cnt+1);
        if(s[ind]==')')
            return f(s,ind+1,cnt-1);
        return f(s,ind+1,cnt+1) || f(s,ind+1,cnt-1) || f(s,ind+1,cnt);
    }

    bool checkValidString(string s) {
        // Brute - using recursion (trying out all possible cases)
        // return f(s,0,0);

        // Optimal - greedy 
        int n=s.size();
        int min=0,max=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min < 0)
                min=0;
            if(max<0)
                return false;
        }
        return min==0;
    }
};