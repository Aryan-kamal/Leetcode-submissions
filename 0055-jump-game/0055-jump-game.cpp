class Solution {
public:
    bool canJump(vector<int>& nums) {
        // -- This logic is not 100% correct --
            // It fails for these type of test cases - 
                // [4,2,0,0,1,1,4,4,4,0,4,0]
                // expected is true but this logic will give you false
            // This logic lands on the maxm value in the range every time which 
            // may not be accurate every time as seen in above example !
             
        // int n=nums.size(),maxi=0;
        // if(n==1)
        //     return true;
        // for(int i=0;i<n;)
        // {
        //     if(nums[i]!=0)
        //         maxi=i+1;
        //     else
        //         return false;
        //     for(int j=i+1;j<=i+nums[i]&&j<n;j++){
        //         if(nums[j]>=nums[maxi])
        //             maxi=j;
        //     }
        //     if(maxi+nums[maxi]>=n-1)
        //         return true;
        //     else if (nums[maxi]==0)
        //         return false;
        //     i=maxi;
        // }
        // return true;

        // -- Correct and optimal greedy code - 
        int n=nums.size(),maxInd=0;
        for(int i=0;i<n;i++){
            if(i>maxInd)
                return false;
            maxInd=max(maxInd,i+nums[i]);
        }
        return true;
    }
};