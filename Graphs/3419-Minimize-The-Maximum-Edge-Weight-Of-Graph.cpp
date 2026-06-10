class Solution {
public:

    bool can(int n,
             vector<vector<int>>& edges,
             int mx) {

        vector<vector<int>> rev(n);

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(w <= mx)
                rev[v].push_back(u);
        }

        vector<int> vis(n,0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int cnt = 1;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int v : rev[u]) {

                if(!vis[v]) {

                    vis[v] = 1;
                    cnt++;
                    q.push(v);
                }
            }
        }

        return cnt == n;
    }

    int minMaxWeight(int n,
                     vector<vector<int>>& edges,
                     int threshold) {

        int lo = 1;
        int hi = 1000000;

        int ans = -1;

        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if(can(n, edges, mid)) {

                ans = mid;
                hi = mid - 1;
            }
            else {

                lo = mid + 1;
            }
        }

        return ans;
    }
};
