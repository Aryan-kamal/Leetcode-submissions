class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int n=words.size(),len=0;
        for(auto it:words){
            string rev=it;
            swap(rev[0],rev[1]);
            if(mp[rev]>0){
                len+=4;
                mp[rev]--;
            }
            else
                mp[it]++;
        }
        for(auto it:mp){
            string word=it.first;
            int cnt=it.second;
            if(word[0]==word[1] && cnt>0){
                len+=2;
                break;
            }
        }
        return len;
    }
};