class Solution {
public:
    int longestPalindrome(int n,
                          vector<vector<int>>& edges,
                          string label) {

        vector<vector<int>> g(n);

        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int N = 1 << n;

        vector<vector<char>> dp(
            N,
            vector<char>(n * n, 0)
        );

        int ans = 1;

        for(int i = 0; i < n; i++) {

            dp[1 << i][i * n + i] = 1;
        }

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            if(label[u] == label[v]) {

                int mask =
                    (1 << u)
                    | (1 << v);

                dp[mask][u * n + v] = 1;
                dp[mask][v * n + u] = 1;

                ans = 2;
            }
        }

        for(int mask = 0; mask < N; mask++) {

            int len = __builtin_popcount(mask);

            for(int u = 0; u < n; u++) {

                for(int v = 0; v < n; v++) {

                    if(!dp[mask][u * n + v])
                        continue;

                    ans = max(ans, len);

                    for(int nu : g[u]) {

                        if(mask & (1 << nu))
                            continue;

                        for(int nv : g[v]) {

                            if(mask & (1 << nv))
                                continue;

                            if(nu == nv)
                                continue;

                            if(label[nu] != label[nv])
                                continue;

                            int newMask =
                                mask
                                | (1 << nu)
                                | (1 << nv);

                            dp[newMask]
                              [nu * n + nv] = 1;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
