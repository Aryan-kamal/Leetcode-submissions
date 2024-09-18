class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0;
        int n=nums.size();;
        for(int j=1;j<n;j++)
        {
            if(nums[j]!=nums[i])
            {
                nums[++i]=nums[j];
            }
        }
        return i+1;
    }
};


// int removeDuplicates(vector<int>& nums) 
//     {
//         set<int> s;
//         int n = nums.size();
//         for(int i=1;i<n;i++)
//             s.insert(nums[i]);
//         int index=0;
//         for(auto i:s)
//         {
//             nums[index]=i;
//             index++;
//         }
//         auto begin=nums.begin()+index;
//         nums.erase(begin, nums.end());
//         return index+1;
//     }