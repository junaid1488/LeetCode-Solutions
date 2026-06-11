class Solution {
public:
    int minFlips(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int ans = 0, mid1 = 0, diff = 0;

        for(int i = 0; i < m / 2; i++) {
            for(int j = 0; j < n / 2; j++) {
                int ones = g[i][j]
                         + g[i][n - 1 - j]
                         + g[m - 1 - i][j]
                         + g[m - 1 - i][n - 1 - j];

                ans += min(ones, 4 - ones);
            }
        }

        if(m & 1) {
            int r = m / 2;

            for(int j = 0; j < n / 2; j++) {
                int a = g[r][j];
                int b = g[r][n - 1 - j];

                if(a == b) mid1 += a + b;
                else diff++, ans++;
            }
        }

        if(n & 1) {
            int c = n / 2;

            for(int i = 0; i < m / 2; i++) {
                int a = g[i][c];
                int b = g[m - 1 - i][c];

                if(a == b) mid1 += a + b;
                else diff++, ans++;
            }
        }

        if(diff == 0 && mid1 % 4) ans += 2;

        if((m & 1) && (n & 1))
            ans += g[m / 2][n / 2];

        return ans;
    }
};
