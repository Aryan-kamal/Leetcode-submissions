class Solution {
public:
    // M-1 -
    void function(vector<int>& nums, int n,vector<vector<int>> &ans,
                    vector<int>temp,int ind){
        // if(ind == n)
        //     return;  // base condn not required !
        ans.push_back(temp);
        for(int i=ind;i<n;i++)
        {
            if(i == ind || nums[i]!=nums[i-1])
            {
                temp.push_back(nums[i]);
                function(nums,n,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        function(nums,n,ans,temp,0);
        return ans;
    }

    // M-2 
    // void function (int ind,vector<int>& temp,vector<int>& nums,int n,set<vector<int>>&ans){
    //     if(ind>=n)
    //     {
    //         ans.insert(temp);
    //         return;
    //     }
    //     temp.push_back(nums[ind]);
    //     function(ind+1,temp,nums,n,ans);
    //     temp.pop_back();
    //     function(ind+1,temp,nums,n,ans);
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     set<vector<int>>ans;
    //     int n=nums.size();
    //     vector<int> temp;
    //     sort(nums.begin(),nums.end());
    //     function(0,temp,nums,n,ans);
    //     vector<vector<int>>ans1(ans.begin(),ans.end());
    //     return ans1;
    // }
};