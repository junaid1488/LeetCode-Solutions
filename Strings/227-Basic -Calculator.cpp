class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        long long num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push_back(num);
                }
                else if (op == '-') {
                    st.push_back(-num);
                }
                else if (op == '*') {
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top * num);
                }
                else if (op == '/') {
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top / num); // truncates toward zero
                }

                op = c;
                num = 0;
            }
        }

        int ans = 0;
        for (int x : st) {
            ans += x;
        }

        return ans;
    }
};
