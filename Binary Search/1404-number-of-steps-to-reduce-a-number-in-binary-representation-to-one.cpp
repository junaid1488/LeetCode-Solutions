class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int ans = 0;

        for(int i = s.size() - 1; i > 0; i--) {

            int bit = (s[i] - '0') + carry;

            if(bit == 1) {
                ans += 2;
                carry = 1;
            }
            else {
                ans += 1;
            }
        }

        return ans + carry;
    }
};
