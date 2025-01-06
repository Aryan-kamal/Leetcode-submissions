class Solution {
public:
    bool search(string s, vector<string>& dict) {
        return find(dict.begin(), dict.end(), s) != dict.end();
    }

    // // M-1 (brute using recursion) (gives TLE)
    // bool function(string s, vector<string>& wordDict,int ind){
    //     if(ind>=s.size())
    //         return true;
    //     string temp="";
    //     for(int i=ind;i<s.size();i++){
    //         temp+=s[i];
    //         // if temp is found then recursively check the rest of the string
    //         if(search(temp,wordDict) && function(s, wordDict, ind+temp.size()))
    //                 return true;  // If all the strings can be segmented, return true
    //     }
    //     return false; // If no valid segmentation found, return false
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     return function(s,wordDict,0);
    // }

    // M-2 (memoization) -
    bool function(const string& s, vector<string>& wordDict, int ind, vector<int>& memo) {
        if (ind >= s.size()) 
            return true;
        if (memo[ind] != -1) 
            return memo[ind];
        string temp = "";
        for (int i = ind; i < s.size(); i++) {
            temp += s[i];
            // If temp is found in wordDict and the rest can also be segmented
            if (search(temp, wordDict) && function(s, wordDict, i + 1, memo))
                return memo[ind] = true;  // Memoize and return true
        }
        return memo[ind] = false;  // Memoize and return false if no valid segmentation is found
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return function(s, wordDict, 0, memo);
    }
};


// alternative of after line 13
// if(search(temp,wordDict))
// {
//     // Recursively check the rest of the string
//     if (function(s, wordDict, ind+temp.size()))
//         return true;  // If the rest can be segmented, return true
// }