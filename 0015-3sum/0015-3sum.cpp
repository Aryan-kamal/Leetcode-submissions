class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        // M-1 - brute, nested 3 loops, n^3

        // M-2 - better, using hashing, n^2 log n
        // set<vector<int>> st;
        // int n = arr.size();
        // for (int i = 0; i < n; i++) {
        //     set<int> hashset;
        //     for (int j = i + 1; j < n; j++) {
        //         // Calculate the 3rd element:
        //         int third = -(arr[i] + arr[j]);

        //         // Find the element in the set:
        //         if (hashset.find(third) != hashset.end()) {
        //             vector<int> temp = {arr[i], arr[j], third};
        //             sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(arr[j]);
        //     }
        // }
        // // store the set in the answer:
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        // M-3 - optimal using 2 pointers (n^2)
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue; // skip duplicates for i

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else {
                    res.push_back({arr[i], arr[left], arr[right]});

                    // skip duplicates for left & right
                    while (left < right && arr[left] == arr[left + 1])
                        left++;
                    while (left < right && arr[right] == arr[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};