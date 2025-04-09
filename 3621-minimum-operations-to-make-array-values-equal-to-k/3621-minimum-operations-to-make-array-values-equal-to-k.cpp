class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        set<int>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>k){
                if(s.count(nums[i])==0){
                    cnt++;
                    s.insert(nums[i]);
                }
            }
            else if (nums[i]<k)
                return -1;
        }
        return cnt;

        // M-2 (same logic but wo using cnt)
        // unordered_set<int> st;
        // for(int &x : nums) {
        //     if(x < k)
        //         return -1;
        //     else if(x > k)
        //         st.insert(x);  
        // }
        // return st.size();
    }
};