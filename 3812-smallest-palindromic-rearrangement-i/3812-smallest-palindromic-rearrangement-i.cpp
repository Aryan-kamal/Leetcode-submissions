class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid = n / 2;
        if (n <=2)
            return s;

        string wd = s.substr(0, n / 2); // half string generation
        sort(wd.begin(), wd.end());

        string sd = wd;

        reverse(sd.begin(), sd.end()); // reversal

        if (n % 2 == 1)
            wd += s[mid]; // append middle char as is if n is odd
        
        return wd + sd; // concatenate
    }
};