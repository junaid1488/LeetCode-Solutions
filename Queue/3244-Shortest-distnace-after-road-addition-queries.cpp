class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> nxt(n);
        for (int i = 0; i < n - 1; i++) {
            nxt[i] = i + 1;
        }

        int dist = n - 1;
        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (nxt[u] < v) {
                
                int cur = nxt[u];
                int removed = 0;

                while (cur < v) {
                    removed++;
                    int temp = nxt[cur];
                    nxt[cur] = 0;      // mark removed
                    cur = temp;
                }

                nxt[u] = v;
                dist -= removed;
            }

            ans.push_back(dist);
        }

        return ans;
    }
};
