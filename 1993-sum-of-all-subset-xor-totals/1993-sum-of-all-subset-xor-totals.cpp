class Solution {
public:
    // M-1
    // void function(int ind, vector<int>& temp, vector<int>& nums, int n,
    //               vector<vector<int>>& ans) {
    //     if (ind >= n) {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     temp.push_back(nums[ind]);
    //     function(ind + 1, temp, nums, n, ans);
    //     temp.pop_back();
    //     function(ind + 1, temp, nums, n, ans);
    // }
    // M-2 
    int fn(vector<int>& nums, int i, int currXOR) {
        if (i == nums.size())
            return currXOR;
        int take = fn(nums, i + 1, currXOR ^ nums[i]);
        int notTake = fn(nums, i + 1, currXOR);
        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        // M-1 Brute -
        // vector<vector<int>> ans;
        // int n = nums.size();
        // vector<int> temp;
        // function(0, temp, nums, n, ans);
        // int sum = 0;
        // for (const auto& vec : ans) {
        //     int xorTotal = 0;
        //     for (int num : vec)
        //         xorTotal ^= num;
        //     sum += xorTotal;
        // }
        // return sum;

        // M-2
        return fn(nums, 0, 0);

        // M-3 -
        // int orSum = 0;
        // // Compute the bitwise OR of all numbers in the array.
        // for (int num : nums) {
        //     orSum |= num;
        // }
        // // Multiply the OR sum by 2^(n-1)
        // return orSum * (1 << (nums.size() - 1));

        // M-4 -
        // int subsets=(1<<nums.size());
        // int sum=0;
        // for(int num=0;num<subsets;num++)
        // {
        //     int xorTot=0;
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         if(num&(1<<i))
        //             xorTot^=nums[i];
        //     }
        //     sum+=xorTot;
        // }
        // return sum;
    }
};