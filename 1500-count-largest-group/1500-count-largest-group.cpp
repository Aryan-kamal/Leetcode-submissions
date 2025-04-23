class Solution {
public:
    int digitSum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        vector<int> count(37, 0); // index as sum -> count 
        for (int i = 1; i <= n; i++)
            count[digitSum(i)]++;
        
        int maxi = *max_element(count.begin(), count.end()); //largest size group 
        int  grpsCount= 0;
        for (auto cnt : count)
            if (cnt == maxi)
                grpsCount++;

        return grpsCount;
    }
};
