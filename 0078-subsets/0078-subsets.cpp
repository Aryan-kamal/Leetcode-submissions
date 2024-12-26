class Solution {
public:
    vector<vector<int>>ans;
    void function (int ind,vector<int>& temp,vector<int>& nums,int n){
        if(ind>=n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        function(ind+1,temp,nums,n);
        temp.pop_back();
        function(ind+1,temp,nums,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // M-1 - using Bit -
        // int subsets=(1<<nums.size());
        // vector<vector<int>>vec(subsets);
        // for(int num=0;num<subsets;num++)
        // {
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         if(num&(1<<i))
        //             vec[num].push_back(nums[i]);
        //     }
        // }
        // return vec;


        //  M-2 -- using recursion
        int n=nums.size();
        vector<int> temp;
        function(0,temp,nums,n);
        return ans;
    }
};