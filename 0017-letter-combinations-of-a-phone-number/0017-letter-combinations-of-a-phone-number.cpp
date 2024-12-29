class Solution {
public:
    void function(string &digits,string &temp,vector<string>&ans,int ind,map<char,string> &phoneKeypad){
        if(ind==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string x=phoneKeypad[digits[ind]];
        for(int i=0;i<x.size();i++)
        {
            temp.push_back(x[i]);
            function(digits,temp,ans,ind+1,phoneKeypad);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        map<char,string> phoneKeypad;
        phoneKeypad['2'] = "abc";
        phoneKeypad['3'] = "def";
        phoneKeypad['4'] = "ghi";
        phoneKeypad['5'] = "jkl";
        phoneKeypad['6'] = "mno";
        phoneKeypad['7'] = "pqrs";
        phoneKeypad['8'] = "tuv";
        phoneKeypad['9'] = "wxyz";
        vector<string>ans;
        string temp="";
        function(digits,temp,ans,0,phoneKeypad);
        return ans;
    }
};