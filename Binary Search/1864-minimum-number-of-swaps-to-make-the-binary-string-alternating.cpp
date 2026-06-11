class Solution {

    int solve(string &s, char start) {
        int mismatch = 0;

        for(int i = 0; i < s.size(); i++) {

            char need =
                (i % 2 == 0)
                ? start
                : (start == '0' ? '1' : '0');

            if(s[i] != need)
                mismatch++;
        }

        return mismatch / 2;
    }

public:
    int minSwaps(string s) {

        int zero = count(s.begin(), s.end(), '0');
        int one = s.size() - zero;

        if(abs(zero - one) > 1)
            return -1;

        if(zero > one)
            return solve(s, '0');

        if(one > zero)
            return solve(s, '1');

        return min(
            solve(s, '0'),
            solve(s, '1')
        );
    }
};
