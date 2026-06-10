class Solution {
public:
    int largestPathValue(string colors,
                         vector<vector<int>>& edges) {

        int n = colors.size();

        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        queue<int> q;

        vector<vector<int>> dp(
            n,
            vector<int>(26, 0)
        );

        for (int i = 0; i < n; i++) {

            if (indeg[i] == 0)
                q.push(i);

            dp[i][colors[i] - 'a'] = 1;
        }

        int processed = 0;
        int ans = 0;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            processed++;

            for (int c = 0; c < 26; c++)
                ans = max(ans, dp[u][c]);

            for (int v : g[u]) {

                for (int c = 0; c < 26; c++) {

                    dp[v][c] = max(
                        dp[v][c],
                        dp[u][c] +
                        (c == colors[v] - 'a')
                    );
                }

                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        return processed == n
            ? ans
            : -1;
    }
};
