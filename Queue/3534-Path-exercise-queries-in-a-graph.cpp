class Solution {
public:
    vector<int> minDifference(int n, vector<int>& nums, int maxDiff,
                              vector<vector<int>>& queries) {

        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> pos(n);
        vector<int> comp(n);

        for (int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }

        int cid = 0;
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        vector<int> nxt(n);

        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n &&
                   v[r + 1].first - v[l].first <= maxDiff)
                r++;

            nxt[l] = r;
        }

        int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int u = pos[q[0]];
            int vpos = pos[q[1]];

            if (u == vpos) {
                ans.push_back(0);
                continue;
            }

            if (u > vpos) swap(u, vpos);

            if (comp[u] != comp[vpos]) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < vpos) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};
