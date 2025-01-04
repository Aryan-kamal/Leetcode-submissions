class Solution {
public:
    void function(int n,string temp,vector<string> &ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(temp.back()=='1'){
            function(n,temp+"1",ans);
            // temp.pop_back();
            function(n,temp+"0",ans);
        }
        else
            function(n,temp+"1",ans);
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        function(n,"0",ans);
        function(n,"1",ans);
        return ans;
    }
};