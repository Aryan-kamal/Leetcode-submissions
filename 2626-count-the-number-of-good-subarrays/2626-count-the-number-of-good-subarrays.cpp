class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>hash;
        int i=0,j=0;
        long long pairs=0,cnt=0;
        while(j<n){
            pairs+=hash[nums[j]];
            hash[nums[j]]++;
            while(pairs>=k){
                cnt+=(n-j);
                hash[nums[i]]--;
                pairs-=hash[nums[i]];
                i++;
            }
            j++;
        }
        return cnt;
    }
};