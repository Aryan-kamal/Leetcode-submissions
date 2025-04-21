class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();

        // M-1 (brute TLE)-  
        // int cnt=0;
        // for(int i=lower;i<=upper;i++){
        //     int next=i;
        //     int j=0;
        //     for(j=0;j<n;j++){
        //         next+=differences[j];
        //         if(next<lower || next>upper)
        //             break;
        //     }
        //     if(j==n)
        //         cnt++;
        // }
        // return cnt;

        // M-2 optimal
        long sum = 0, maxi = 0, mini = 0; // we can any value here in place of 0 but all 3 variable will have same value 
        for (int i : differences) {
            sum += i;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        return max(0L, upper - lower - maxi + mini + 1);
    }
};