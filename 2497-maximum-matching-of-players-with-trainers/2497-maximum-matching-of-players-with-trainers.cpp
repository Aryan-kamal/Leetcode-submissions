class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Both below codes are using sorting + 2 pointers - 
        int n=players.size(),m=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        // int a=0,cnt=0;
        // for(int i=0;i<n;i++){
        //     if(a>=m)
        //         break;
        //     if(players[i]<=trainers[a])
        //         cnt++;
        //     else
        //         i--;
        //     a++;
        // }
        // return cnt;

        int l=0,r=0;
        while(l<m && r<n){
            if(players[r]<=trainers[l])
                r++;
            l++;
        }
        return r;
    }
};