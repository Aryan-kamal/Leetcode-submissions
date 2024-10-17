class Solution {
public:
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1,int ind2)
    {
        if (arr1[ind1] > arr2[ind2])
            swap(arr1[ind1], arr2[ind2]);
    }
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {

        // M-1 - using 2 pointers and 1 extra array of m+n length and then again
        // filling original arrays with extra array values  -


        // M-2 - (2 pointers and sorting)
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


        // M-3 -- Gap method --
        // a) copying before -
        // Step 1: Copy nums2 into nums1 starting from index n
        for (int i = 0; i < m; i++)
            arr1[n + i] = arr2[i];  // Filling the empty part of nums1 with nums2 elements
        int len = n + m;
        int gap = (len / 2) + (len % 2); // Initialize the gap
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                if (left < len && right < len) // all 3 conditions as every element is in array 1 only
                    swapIfGreater(arr1, arr1, left, right);
                left++;
                right++;
            }
            // Reduce the gap for the next iteration
            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }

        // b) copying afterwards-
        // int len = n + m;
        // int gap = (len / 2) + (len % 2);
        // while (gap > 0) {
        //     int left = 0;
        //     int right = left + gap;
        //     while (right < len) {
                
        //         if (left < n && right >= n) // Case 1: left in arr1 and right in arr2
        //             swapIfGreater(arr1, arr2, left, right - n);
        //         else if (left >= n) // Case 2: both pointers in arr2
        //             swapIfGreater(arr2, arr2, left - n, right - n);
        //         else // Case 3: both pointers in arr1
        //             swapIfGreater(arr1, arr1, left, right);
        //         left++;
        //         right++;
        //     }
        //     // Reduce the gap for the next iteration
        //     if (gap == 1)
        //         break;
        //     gap = (gap / 2) + (gap % 2);
        // }
        // for (int i = 0; i < m; i++) 
        //     arr1[n + i] = arr2[i];

    }
};