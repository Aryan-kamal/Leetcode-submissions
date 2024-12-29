class Solution {
public:
    void function (int ind,vector<int>& temp,vector<int>& nums,int n,set<vector<int>>&ans){
        if(ind>=n)
        {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        function(ind+1,temp,nums,n,ans);
        temp.pop_back();
        function(ind+1,temp,nums,n,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        function(0,temp,nums,n,ans);
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};