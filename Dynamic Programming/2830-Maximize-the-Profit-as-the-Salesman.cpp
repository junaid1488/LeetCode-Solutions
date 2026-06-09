class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        vector<vector<pair<int,int>>> start(n);

        for(auto &o : offers)
            start[o[0]].push_back({o[1], o[2]});

        vector<long long> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            dp[i] = dp[i + 1];

            for(auto &[e, g] : start[i])
                dp[i] = max(dp[i],
                            g + dp[e + 1]);
        }

        return dp[0];
    }
};
