class Solution {
public:
    static constexpr int LOG = 14;

    vector<vector<pair<int,int>>> g;
    vector<int> depth;
    vector<vector<int>> up;
    vector<array<int,27>> pref;

    void dfs(int u, int p) {

        for (auto &[v,w] : g[u]) {

            if (v == p) continue;

            depth[v] = depth[u] + 1;

            up[v][0] = u;

            pref[v] = pref[u];
            pref[v][w]++;

            dfs(v,u);
        }
    }

    int lca(int a, int b) {

        if (depth[a] < depth[b])
            swap(a,b);

        int diff = depth[a] - depth[b];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k))
                a = up[a][k];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--) {

            if (up[a][k] != up[b][k]) {
                a = up[a][k];
                b = up[b][k];
            }
        }

        return up[a][0];
    }

    vector<int> minOperationsQueries(int n,
                                     vector<vector<int>>& edges,
                                     vector<vector<int>>& queries) {

        g.resize(n);
        depth.assign(n,0);
        up.assign(n, vector<int>(LOG));
        pref.assign(n,{});

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        dfs(0,-1);

        for (int k = 1; k < LOG; k++) {
            for (int v = 0; v < n; v++) {
                up[v][k] = up[up[v][k-1]][k-1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int u = q[0];
            int v = q[1];

            int L = lca(u,v);

            int len =
                depth[u] +
                depth[v] -
                2 * depth[L];

            int mx = 0;

            for (int w = 1; w <= 26; w++) {

                int cnt =
                    pref[u][w] +
                    pref[v][w] -
                    2 * pref[L][w];

                mx = max(mx,cnt);
            }

            ans.push_back(len - mx);
        }

        return ans;
    }
};
