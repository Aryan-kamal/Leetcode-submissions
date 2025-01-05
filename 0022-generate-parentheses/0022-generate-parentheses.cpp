class Solution {
public:
    void function(int n,string temp,vector<string>&ans,int open,int close){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n)
            function(n,temp+"(",ans,open+1,close);
        if(close<open)
            function(n,temp+")",ans,open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>ans;
        function(n,temp,ans,0,0);
        return ans;
    }
};