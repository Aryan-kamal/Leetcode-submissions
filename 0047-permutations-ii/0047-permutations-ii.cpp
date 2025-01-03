class Solution {
public:
    // M-1 -
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     int n=nums.size();
    //     set<vector<int>>ans;
    //     function(nums,n,ans,0);
    //     vector<vector<int>>ans1(ans.begin(), ans.end());
    //     return ans1;
    // }
    // void function(vector<int>& nums, int n,set<vector<int>>&ans,int ind){
    //     if(ind==n){
    //         ans.insert(nums);
    //         return;
    //     }
    //     for(int i=ind;i<n;i++){
    //         swap(nums[ind],nums[i]);
    //         function(nums,n,ans,ind+1);
    //         swap(nums[ind],nums[i]);
    //     }
    // }

    // M-2 -
    vector<vector<int>> permuteUnique(vector<int>& nums){
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        map<int,int>mp;
        for (int i=0;i<n;i++)
            mp[i] = 0;
        sort(nums.begin(),nums.end());
        function(nums,n,temp,ans,mp);
        return ans;
    }
        void function(vector<int>& nums, int n,vector<int>temp,vector<vector<int>>&ans,map<int,int>&mp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(mp[i] == 0 && (i == 0 || nums[i] != nums[i - 1] || mp[i - 1] == 1)){
                temp.push_back(nums[i]);
                mp[i]=1;
                function(nums,n,temp,ans,mp);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }
};