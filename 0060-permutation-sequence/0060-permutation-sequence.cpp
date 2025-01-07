class Solution {
public:
    string getPermutation(int n, int k) {
        string nums="";
        for (int i = 1; i <= n; i++)
            nums += to_string(i);
        string temp;
        vector<string>ans;
        map<int,int>mp;
        for (int i=0;i<n;i++)
            mp[i] = 0;
        function(nums,n,temp,ans,mp,k);
        return ans[k-1];
    }

    void function(string &nums, int n,string &temp,vector<string>&ans,map<int,int>&mp,int k){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(ans.size()==k)
                break;
            if(mp[i]==0){
                temp.push_back(nums[i]);
                mp[i]=1;
                function(nums,n,temp,ans,mp,k);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }
};