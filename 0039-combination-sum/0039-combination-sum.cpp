class Solution {
public:
    void function(vector<int>& candidates, int target,int n,vector<vector<int>> &ans,
                    vector<int>temp,int ind){
        // M-1 -
        // if(ind==n || target<0)
        // {
        //     if(target==0)
        //         ans.push_back(temp);
        //     return;
        // }
        // target-=candidates[ind];
        // temp.push_back(candidates[ind]);
        // function(candidates,target,n,ans,temp,ind);
        // target+=candidates[ind];
        // temp.pop_back();
        // function(candidates,target,n,ans,temp,ind+1);
        
        // M-2 (little more effective) -
        if(ind==n)
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(candidates[ind]<=target)
        {
            temp.push_back(candidates[ind]);
            function(candidates,target-candidates[ind],n,ans,temp,ind);
            temp.pop_back();
        }
        function(candidates,target,n,ans,temp,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n=candidates.size();
        vector<int>temp;
        function(candidates,target,n,ans,temp,0);
        return ans;
    }
};