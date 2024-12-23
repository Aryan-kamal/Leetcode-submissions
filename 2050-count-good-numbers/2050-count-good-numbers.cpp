class Solution {
public:
long MOD=1000000007;
    long power(long x,long n){
        if(n==0)
            return 1;
        if(n%2==0)
            return power((x*x)%MOD,n/2)%MOD;
        else
            return (x*power(x,n-1))%MOD;
    }
    int countGoodNumbers(long long n) {
        long even=(n+1)/2;
        long odd=n/2;
        return (int)(((power(5, even) % MOD)*(power(4, odd) % MOD)) % MOD);
    }
};