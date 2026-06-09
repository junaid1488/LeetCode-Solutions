class Solution {
public:
    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(minProfit + 1, 0)
        );

        dp[0][0] = 1;

        for(int i = 0; i < group.size(); i++) {

            int g = group[i];
            int p = profit[i];

            for(int members = n; members >= g; members--) {

                for(int prof = minProfit; prof >= 0; prof--) {

                    int np = min(minProfit, prof + p);

                    dp[members][np] =
                        (dp[members][np] +
                         dp[members - g][prof]) % MOD;
                }
            }
        }

        long long ans = 0;

        for(int members = 0; members <= n; members++)
            ans = (ans + dp[members][minProfit]) % MOD;

        return ans;
    }
};
