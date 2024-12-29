class Solution {
public:
    void function(vector<int>& candidates, int target,int n,int k,
    vector<vector<int>> &ans,vector<int>temp,int ind){
        if(target==0 && temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(candidates[i]>target)
                break;
            if(i == ind || candidates[i]!=candidates[i-1])
            {
                temp.push_back(candidates[i]);
                function(candidates,target-candidates[i],n,k,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>candidates={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        function(candidates,n,9,k,ans,temp,0);
        return ans;
    }
};