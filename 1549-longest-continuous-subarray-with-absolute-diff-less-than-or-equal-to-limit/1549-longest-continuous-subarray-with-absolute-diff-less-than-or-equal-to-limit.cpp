class Solution {
public:
    // M-1 (my dimag) (n^2 TLE)-
    // int longestSubarray(vector<int>& nums, int limit) {
    //     int n = nums.size();
    //     int l = 0, r = 0, cnt = 0, ans = INT_MIN, mini = nums[0],
    //         maxi = nums[0];
    //     while (r < nums.size()) {
    //         maxi = max(maxi, nums[r]);
    //         mini = min(mini, nums[r]);
    //         if (maxi - mini <= limit) {
    //             cnt++;
    //             r++;
    //         } else {
    //             ans = max(ans, cnt);
    //             cnt = 0;
    //             l++;r = l;
    //             maxi = mini = nums[r];
    //         }
    //     }
    //     return max(ans, cnt);
    // }

    // CodeStoryWithMik (O(n)) using multiset -
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st; // to store sorted, duplicate elements (also easily deletion)
        int i = 0,j = 0;
        int maxLength = 0;
        while (j < n) {
            st.insert(nums[j]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};