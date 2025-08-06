class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0;
        for(int i=0;i<fruits.size();i++){
            int flag=0;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]!=-1 && fruits[i]<=baskets[j]){
                    baskets[j]=-1;
                    flag=-1;
                    break;
                }
            }
            if(flag==0)
                cnt++;
        }
        return cnt;
    }
};