class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // nlogn using 2 times sorting - 
        // int n = nums.size();
        // if (k == n)
        //     return nums;
        // vector<pair<int, int>> vec(n);
        // for(int i = 0; i < n; i++)
        //     vec[i] = make_pair(i, nums[i]);
        // auto lambda = [](auto &p1, auto& p2) {
        //     return p1.second > p2.second;
        // };
        // sort(begin(vec), end(vec), lambda);
        // sort(begin(vec), begin(vec)+k);
        // vector<int> result;
        // for(int i = 0; i < k; i++)
        //     result.push_back(vec[i].second);
        // return result;


        // nlogk using heap - 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size() > k) 
                pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            ans[i] = nums[ans[i]];
        return ans;


        // n using nth_element - 
        // if (k == nums.size())
        //     return nums;
        // vector<int> temp(nums); // Copy nums to a temp vector to find k largest elements
        // // Use nth_element to put the k largest elements in the first k positions (unordered)
        // nth_element(begin(temp), begin(temp) + k - 1, end(temp), greater<int>()); //Average TC is O(n)
        // int threshold = temp[k - 1]; // Determine the threshold value (k-th largest element)
        // // Count how many times threshold appears in top k elements
        // int countThreshold = count(temp.begin(), temp.begin() + k, threshold); //O(k)
        // vector<int> result;
        // for (int num : nums) {
        //     if (num > threshold)
        //         result.push_back(num);
        //     else if (num == threshold && countThreshold > 0) {
        //         result.push_back(num);
        //         countThreshold--;
        //     }
        //     if (result.size() == k)
        //         break;
        // }
        // return result;
    }
};