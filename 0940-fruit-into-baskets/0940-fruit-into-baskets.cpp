class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int n=fruits.size();
        // map<int,int> mp;
        // int l=0,r=0,ans=0,maxfruits=0;
        // while(r<n)
        // {
        //     mp[fruits[r]]++;
        //     int m=mp.size();
        //     if(m>2)
        //     {
        //         while(mp.size()>2)
        //         {
        //             mp[fruits[l]]--;
        //             if(mp[fruits[l]]==0)
        //                 mp.erase(fruits[l]);
        //             l++;
        //         }
        //     }
        //     ans=r-l+1;
        //     maxfruits=max(maxfruits,ans); 
        //     r++;
        // }
        // return maxfruits;

        // Most optimal --
        int n=fruits.size();
        map<int,int> mp;
        int l=0,r=0,maxfruits=0;
        while(r<n)
        {
            mp[fruits[r]]++;
            if(mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)
                    mp.erase(fruits[l]);
                l++;
            }
            maxfruits=max(maxfruits,r-l+1); 
            r++;
        }
        return maxfruits;
    }
};