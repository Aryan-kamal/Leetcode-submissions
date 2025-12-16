class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int n=nums.size();
        int cnt=1;
        int maxi=cnt;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
//please upvote..
};