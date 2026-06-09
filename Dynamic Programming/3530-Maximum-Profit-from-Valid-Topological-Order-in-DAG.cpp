class Solution {
public:
    long long maxProfit(int n,
                        vector<vector<int>>& edges,
                        vector<int>& score) {

        vector<int> pre(n, 0);

        for(auto &e : edges)
            pre[e[1]] |= (1 << e[0]);

        int N = 1 << n;

        vector<long long> dp(N, -1);
        dp[0] = 0;

        for(int mask = 0; mask < N; mask++) {

            if(dp[mask] == -1) continue;

            int pos = __builtin_popcount(mask) + 1;

            for(int i = 0; i < n; i++) {

                if(mask >> i & 1) continue;

                if((pre[i] & ~mask) == 0) {

                    int nxt = mask | (1 << i);

                    dp[nxt] = max(
                        dp[nxt],
                        dp[mask] + 1LL * score[i] * pos
                    );
                }
            }
        }

        return dp[N - 1];
    }
};
