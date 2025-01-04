class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // M-1 (brute)
        // find all permutations using recrsion and then find and check each of them in s2

        // M-2 (using sorting and sliding window)
        // int len1 = s1.size();
        // int len2 = s2.size();
        // if (len1 > len2) 
        //     return false;
        // sort(s1.begin(), s1.end()); // Sort s1 to use it as a reference for comparison
        // // Traverse s2 with a sliding window of length equal to s1
        // for (int i = 0; i <= len2 - len1; i++) {
        //     string window = s2.substr(i, len1);
        //     sort(window.begin(), window.end());
        //     if (window == s1)
        //         return true;
        // }
        // return false;

        // M-3 (using hash table, frequency count method & sliding window) -
        // int len1 = s1.size();
        // int len2 = s2.size();
        // if (len1 > len2) 
        //     return false;
        // map<char, int> mp1, mp2;
        // for (int i = 0; i < len1; i++)
        //     mp1[s1[i]]++;
        // int i = 0, j = 0; 
        // while (j < len2) {
        //     mp2[s2[j]]++;
        //     if (j - i + 1 > len1) {
        //         mp2[s2[i]]--;
        //         if (mp2[s2[i]] == 0)
        //             mp2.erase(s2[i]);
        //         i++;
        //     }
        //     if (mp1 == mp2)
        //         return true;
        //     j++;
        // }
        // return false;

        // M-4(optimised M-3) -
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) 
            return false;
        map<char, int> mp;
        for (int i = 0; i < len1; i++)
            mp[s1[i]]++;
        int i = 0, j = 0; 
        while (j < len2) {
            mp[s2[j]]--;
            if (j - i + 1 > len1) {
                mp[s2[i]]++;
                i++;
            }
            int flag=0;
            // checking if all values are zero in mp (if all values = 0 then it is a valid substring)
            for (const auto& pair : mp) {
                if (pair.second != 0) {
                    flag=1;  // set flag to 1 as soon as a non-zero value is found
                    break;
                }
            }
            if(flag==0)
                return true; 
            j++;
        }
        return false;
    }
};