class Solution {
public:
    void function(vector<int>& candidates, int target,int n,vector<vector<int>> &ans,
                    vector<int>temp,int ind){
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind == n)
            return;
        for(int i=ind;i<n;i++)
        {
            if(candidates[i]>target)
                break;
            if(i == ind || candidates[i]!=candidates[i-1])
            {
                temp.push_back(candidates[i]);
                function(candidates,target-candidates[i],n,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n=candidates.size();
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        function(candidates,target,n,ans,temp,0);
        return ans;
    }
};