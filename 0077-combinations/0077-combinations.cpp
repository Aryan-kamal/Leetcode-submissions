class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        vector<int> temp;
        vector<vector<int>>ans;
        function(0,temp,nums,n,ans,k);
        return ans;
    }
    void function (int ind,vector<int>& temp,vector<int>& nums,int n,vector<vector<int>>&ans,int k){
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        if(ind>=n)
            return;
        temp.push_back(nums[ind]);
        function(ind+1,temp,nums,n,ans,k);
        temp.pop_back();
        function(ind+1,temp,nums,n,ans,k);
    }
};