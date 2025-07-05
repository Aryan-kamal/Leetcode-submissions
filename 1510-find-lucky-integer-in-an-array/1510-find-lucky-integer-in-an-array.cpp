class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        for(auto num:arr)
            mp[num]++;
        for(auto pair:mp){
            if(pair.first==pair.second)
                ans=max(ans,pair.first);
        }
        return ans==INT_MIN?-1:ans;
    }
};