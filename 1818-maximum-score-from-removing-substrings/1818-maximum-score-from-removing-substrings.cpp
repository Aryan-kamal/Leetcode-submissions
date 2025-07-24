// (TC and SC - n)
class Solution {
public:
    int fn(string s, int n, string sub, stack<char>& st) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (!st.empty() && ch == sub[1] && st.top() == sub[0]) {
                st.pop();
                cnt++;
            } else
                st.push(ch);
        }
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int count = 0, score = 0;
        stack<char> st;
        string max = "ab", min = "ba"; // let x>y
        if (x < y) {
            swap(x, y);
            swap(max, min);
        }

        //1st pass
        count = fn(s, n, max, st);
        score += (count * x);

        // reset
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        n = s.size();

        // 2nd pass
        count = fn(s, n, min, st);
        score += (count * y);

        return score;
    }
};