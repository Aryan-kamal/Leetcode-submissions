class Solution {
public:
    static bool comp(vector<int> val1,vector<int> val2){
        return val1[1]>val2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Greedy soln (Knapsack problem) -
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int tot=0;
        for(int i =0;i<n;i++){
            if(truckSize>=boxTypes[i][0]){
                tot+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                tot+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return tot;
    }
};