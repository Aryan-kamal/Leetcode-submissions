class Solution {
public:
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1,int ind2) {
        if (arr1[ind1] > arr2[ind2])
            swap(arr1[ind1], arr2[ind2]);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // M-1 - using 2 pointers and 1 extra array of m+n length and then again
        // filling original arrays with extra array values  -

        // M-2 -
        // int left = n - 1;
        // int right = 0;
        // while (left >= 0 && right < m) {
        //     if (arr1[left] > arr2[right]) {
        //         swap(arr1[left], arr2[right]);
        //         left--,
        //         right++;
        //     }
        //     else
        //         break;
        // }
        // sort(arr1, arr1 + n);
        // sort(arr2, arr2 + m);

        // M-3 -- Gap method
        // Step 1: Copy nums2 into nums1 starting from index m
        for (int i = 0; i < n; i++) 
            nums1[m + i] = nums2[i];
        int len = m + n;
        int gap = (len / 2) + (len % 2); // Initialize the gap
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                if (left < m && right < m) // Case 1: both pointers in nums1
                    swapIfGreater(nums1, nums1, left, right);
                else if (left < m && right >= m)  // Case 2: left in nums1 and right in nums2
                    swapIfGreater(nums1, nums1, left, right);
                else // Case 3: both pointers in nums2
                    swapIfGreater(nums1, nums1, left, right);
                left++;
                right++;
            }
            // Reduce the gap for the next iteration
            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};