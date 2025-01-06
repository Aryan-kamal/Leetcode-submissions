class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void function(string &s,vector<vector<string>>&ans,int ind,vector <string>&temp1){
        if(ind>=s.size()){
            ans.push_back(temp1);
            return;
        }
        string temp="";
        for(int i=ind;i<=s.size();i++){
            temp+=s[i];
            if(isPalindrome(temp)){
                temp1.push_back(temp);
                function(s,ans,i+1,temp1);
                temp1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector <string>temp1;
        function(s,ans,0,temp1);
        return ans;
    }
};