class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int hills=0,valleys=0;
        int v=0,h=0;
        int prev=nums[0],curr=0;
        for(int i=1;i<n;i++){
            curr=nums[i];
            if(curr>prev){
                h=1;
                if(v==1){
                    valleys++;
                    v=0;
                }
            }
            else if(curr<prev){
                v=1;
                if(h==1){
                    hills++;
                    h=0;
                }
            }
            prev=curr;
        }
        return hills+valleys;
    }
};