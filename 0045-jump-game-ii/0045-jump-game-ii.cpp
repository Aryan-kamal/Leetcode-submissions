class Solution {
public:
    // recursive fn -
    int f(int ind,int jumps,int& n,vector<int>& nums){
        if(ind>=n-1)
            return jumps;
        int mini=INT_MAX;
        for(int i=1;i<=nums[ind];i++)
            mini=min(mini,f(ind+i,jumps+1,n,nums));
        return mini;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();

        // using recurion (convert it to DP to optimise it)
        // return f(0,0,n,nums);

        // Optimal - using 2 pointers(range based greedy soln)
        int jumps=0,l=0,r=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++)
                farthest=max(farthest,i+nums[i]);
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};