class Solution {
public:
    int minTrioDegree(int n,
                      vector<vector<int>>& edges) {

        vector<int> deg(n + 1, 0);

        vector<vector<int>> adj(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u][v] = 1;
            adj[v][u] = 1;

            deg[u]++;
            deg[v]++;
        }

        int ans = INT_MAX;

        for(int u = 1; u <= n; u++) {

            for(int v = u + 1; v <= n; v++) {

                if(!adj[u][v])
                    continue;

                for(int w = v + 1; w <= n; w++) {

                    if(adj[u][w] &&
                       adj[v][w]) {

                        ans = min(
                            ans,
                            deg[u]
                            + deg[v]
                            + deg[w]
                            - 6
                        );
                    }
                }
            }
        }

        return ans == INT_MAX
            ? -1
            : ans;
    }
};
