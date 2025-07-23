class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string safe = "abc";
        int times;

        for (char c : s) {
            st.push(c);
            if (c == 'c') {
                times = 3;
                while (!st.empty() && times--) {
                    if (safe[times] != st.top()) {
                        return false; // Invalid sequence
                    }
                    st.pop();
                }
                if (times > 0) {
                    return false; // Invalid sequence
                }
            }
        }

        return st.empty() ? true : false;
    }
};