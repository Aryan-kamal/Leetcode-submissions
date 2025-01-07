class Solution {
public:
    // M-1 (brute) (generate all permuations and return ans[k-1])

    // M-2 (optimised M-1) (we can more optimise the SC by not storing
    // permutations in ans) string getPermutation(int n, int k) {
    //     string nums="";
    //     for (int i = 1; i <= n; i++)
    //         nums += to_string(i);
    //     string temp;
    //     vector<string>ans;
    //     map<int,int>mp;
    //     for (int i=0;i<n;i++)
    //         mp[i] = 0;
    //     function(nums,n,temp,ans,mp,k);
    //     return ans[k-1];
    // }
    // void function(string &nums, int n,string
    // &temp,vector<string>&ans,map<int,int>&mp,int k){
    //     if(temp.size()==n){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(ans.size()==k)
    //             break;
    //         if(mp[i]==0){
    //             temp.push_back(nums[i]);
    //             mp[i]=1;
    //             function(nums,n,temp,ans,mp,k);
    //             temp.pop_back();
    //             mp[i]=0;
    //         }
    //     }
    // }

    // M-3 (optimal) (without using recursion) -
    string getPermutation(int n, int k) {
        int fact = 1;
        string res = "";
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            arr.push_back(i);
        }
        k--; // we are using zero based indexing
        while (arr.size() > 0) {
            fact = fact / arr.size();
            res += to_string(arr[k / fact]);
            arr.erase(arr.begin() + k / fact);
            k = k % fact;
        }
        return res;
    }
};

