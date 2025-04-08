class Solution {
public:
    // check fn to check whether all right elements are unique or not 
    // bool check(vector<int>& nums, int start) {
    //     unordered_set<int> st;
    //     for (int j = start; j < n; j++) {
    //         if (st.count(nums[j]))
    //             return false;
    //         st.insert(nums[j]);
    //     }
    //     return true;
    // }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        // M - 1 (my first submission)

        // M-2 brute
        // int ops = 0;
        // for (int i = 0; i < n; i += 3) {
        //     if (check(nums, i) == true) {
        //         return ops;
        //     }
        //     ops++;
        // }
        // return ops;

        // M-3 - optimal -
        unordered_set<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.count(nums[i]))
                return ceil((i + 1) / 3.0);
            st.insert(nums[i]);
        }
        return 0;
    }
};