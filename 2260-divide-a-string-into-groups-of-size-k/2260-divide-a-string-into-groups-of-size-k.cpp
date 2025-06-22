class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        string temp = "";
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            temp += ch;
            if (temp.length() == k) {
                ans.push_back(temp);
                temp = "";
            }
        }
        if (temp.length() != 0) {
            while (temp.size() < k)
                temp += fill;
            ans.push_back(temp);
        }
        return ans;
    }
};

// for (int i = 0; i < n; i++) {
//             char ch = s[i];
//             if (temp.length() < k)
//                 temp += ch;
//             else {
//                 ans.push_back(temp);
//                 temp = ch;
//             }
//         }
//         while (temp.size() < k)
//             temp += fill;
//         ans.push_back(temp);
//         return ans;