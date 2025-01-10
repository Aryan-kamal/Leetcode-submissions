class Solution {
public:
    // M-1 (brute, TLE)
    // long long solve(string& s) {
    //     stack<long long> stk;
    //     long long current = 0;
    //     char operation = '+';
    //     for (int i = 0; i < s.length(); ++i) {
    //         char ch = s[i];
    //         if (isdigit(ch))
    //             current = current * 10 + (ch - '0');
    //         if (!isdigit(ch) && ch != ' ' || i == s.length() - 1) {
    //             if (operation == '+')
    //                 stk.push(current);
    //             else if (operation == '-')
    //                 stk.push(-current);
    //             else if (operation == '*') {
    //                 long long top = stk.top();
    //                 stk.pop();
    //                 stk.push(top * current);
    //             }
    //             operation = ch;
    //             current = 0;
    //         }
    //     }
    //     long long result = 0;
    //     while (!stk.empty()) {
    //         result += stk.top();
    //         stk.pop();
    //     }
    //     return result;
    // }
    // void function(string num, int target, string temp,vector<string>& ans, int ind) {
    //     if (ind == num.length()) {
    //         if (solve(temp) == target)
    //             ans.push_back(temp);
    //         return;
    //     }
    //     string part="";
    //     for (int i = ind; i < num.length(); i++) {
    //         part+=num[i];
    //         if (ind == 0)
    //             function(num, target, temp + part, ans, i + 1);
    //         else {
    //             function(num, target, temp + "+" + part, ans, i + 1);
    //             function(num, target, temp + "-" + part, ans, i + 1);
    //             function(num, target, temp + "*" + part, ans, i + 1);
    //         }
    //         if (num[ind] == '0') // Avoid numbers with leading zero
    //             break;
    //     }
    // }
    // vector<string> addOperators(string num, int target) {
    //     vector<string> ans;
    //     if (num.empty())
    //         return ans;
    //     function(num, target, "", ans, 0);
    //     return ans;
    // }

    // M-2 (optimal)
    void function(string num, int target, int index, long long prevNum, long long currResult, string expr, vector<string>& ans) {
        if (index == num.length()) {
            if (currResult == target)
                ans.push_back(expr);
            return;
        }
        string currNumStr = "";
        long long currNum = 0;
        for (int i = index; i < num.length(); i++) {
            if (i > index && num[index] == '0') 
                break;  // handle leading zeros
            currNumStr += num[i];
            currNum = currNum * 10 + (num[i] - '0');
            if (index == 0)
                function(num, target, i + 1, currNum, currNum, expr + currNumStr, ans);
            else {
                function(num, target, i + 1, currNum, currResult + currNum, expr + "+" + currNumStr, ans);
                function(num, target, i + 1, -currNum, currResult - currNum, expr + "-" + currNumStr, ans);
                function(num, target, i + 1, prevNum * currNum, currResult - prevNum + (prevNum * currNum), expr + "*" + currNumStr, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        function(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};