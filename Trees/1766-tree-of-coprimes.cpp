class Solution {
public:
    vector<int> ans;
    vector<vector<int>> g;
    vector<vector<pair<int,int>>> st;
    vector<int> nums;

    void dfs(int u, int parent, int depth) {

        int bestDepth = -1;
        int bestNode = -1;

        for (int v = 1; v <= 50; v++) {

            if (__gcd(nums[u], v) == 1 && !st[v].empty()) {

                auto [d, node] = st[v].back();

                if (d > bestDepth) {
                    bestDepth = d;
                    bestNode = node;
                }
            }
        }

        ans[u] = bestNode;

        st[nums[u]].push_back({depth, u});

        for (int nxt : g[u]) {
            if (nxt != parent) {
                dfs(nxt, u, depth + 1);
            }
        }

        st[nums[u]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums_,
                            vector<vector<int>>& edges) {

        nums = nums_;
        int n = nums.size();

        ans.assign(n, -1);
        g.assign(n, {});
        st.assign(51, {});

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, -1, 0);

        return ans;
    }
};
