class Solution {
public:
    // M-1 (Using simple recursion and map data stru)
    // void function(vector<int>& nums, int n,vector<int>temp,vector<vector<int>>&ans,map<int,int>&mp){
    //     if(temp.size()==n){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(mp[i]==0){
    //             temp.push_back(nums[i]);
    //             mp[i]=1;
    //             function(nums,n,temp,ans,mp);
    //             temp.pop_back();
    //             mp[i]=0;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>temp;
    //     vector<vector<int>>ans;
    //     map<int,int>mp;
    //     for (int i=0;i<n;i++)
    //         mp[i] = 0;
    //     function(nums,n,temp,ans,mp);
    //     return ans;
    // }

    // M-2 (using recursion and swapping)(less SC)
    void function(vector<int>& nums, int n,vector<vector<int>>&ans,int ind){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            function(nums,n,ans,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        function(nums,n,ans,0);
        return ans;
    }
};