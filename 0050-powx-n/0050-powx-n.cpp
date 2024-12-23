class Solution {
public:
    double solve(double x,long n){
        if(n==0)
            return 1;
        if(n<0)
            return solve(1/x,-n);
    
        if(n%2==0)
            return solve(x*x,n/2);
        else
            return x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        // Recursive soln - 
        return solve(x,(long)n);

        // Mathematical soln-
        // double ans=1;
        // long long int m=n;
        // if(m<0)
        //     m=-m;
        // while(m>0)
        // {
        //     if(m%2==1)
        //     {
        //         ans*=x;
        //         m--;
        //     }
        //     else
        //     {
        //         m/=2;
        //         x*=x;
        //     }
        // }
        // if(n<0)
        //     return (1.0/ans);
        // return ans;
    }
};