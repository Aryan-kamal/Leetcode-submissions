class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size(),fives=0,tens=0;
        for(int i=0;i<n;i++){
            int num=bills[i];
            if(num==5)
                fives++;
            else if(num==10)
            {
                if(fives<1)
                    return false;
                tens++;
                fives--;
            }
            else{
                if(tens>0 && fives>0){
                    tens--;
                    fives--;
                }
                else if(fives>2)
                    fives-=3;
                else
                    return false;
            }  
        }
        return true;
    }
};