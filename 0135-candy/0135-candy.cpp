class Solution {
public:
    int candy(vector<int>& ratings) {
        // Brute greedy soln (TC-3n, SC-2n)
        // just like better soln, take left and right array also and then find max of their values and then add 

        // Better greedy soln (TC-2n, SC-n)
        // int n=ratings.size();
        // int left[n];
        // left[0]=1;
        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1])
        //         left[i]=left[i-1]+1;
        //     else
        //         left[i]=1;
        // }
        // int curr=1;
        // int sum=max(1,left[n-1]);
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1])
        //         curr++;
        //     else
        //         curr=1;
        //     sum+=max(left[i],curr);
        // }
        // return sum;

        // Optimal greedy soln - using slope concept (TC-n,SC-1)
        
        int n=ratings.size();
        int sum=1,i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak)
                sum+=down-peak;
        }
        return sum;
    }
};