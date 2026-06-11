class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int diff1 = 0, diff2 = 0, ans = INT_MAX;

        for(int i = 0; i < 2 * n; i++) {

            if(t[i] != (i % 2 ? '1' : '0')) diff1++;
            if(t[i] != (i % 2 ? '0' : '1')) diff2++;

            if(i >= n) {
                if(t[i - n] != ((i - n) % 2 ? '1' : '0')) diff1--;
                if(t[i - n] != ((i - n) % 2 ? '0' : '1')) diff2--;
            }

            if(i >= n - 1)
                ans = min(ans, min(diff1, diff2));
        }

        return ans;
    }
};
