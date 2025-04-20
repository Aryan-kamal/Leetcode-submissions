class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        int n=answers.size();
        unordered_map<int, int> hash;
        // Create a hash map
        for(int ans:answers)
            hash[ans]++;
        for (auto& [value, cnt] : hash){
            int min=value+1; // min rabits in a grp
            int grps = ceil((double)cnt/min); // number of grp acc to count (if cnt > min then this line will be effective otherwise if cnt <= min then number of grps will be 1 always)
            ans+=(min*grps); // total rabbits = min rabbits in a grp * number of grps 
        }
        return ans;;
    }
};