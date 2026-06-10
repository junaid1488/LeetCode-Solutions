class Solution {
public:
    vector<int> minDistanceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries) {

        vector<pair<int,int>> a;

        for(int i=0;i<n;i++)
            a.push_back({nums[i],i});

        sort(a.begin(),a.end());

        vector<int> pos(n);
        vector<int> comp(n);

        int cid = 0;

        pos[a[0].second] = 0;
        comp[a[0].second] = 0;

        for(int i=1;i<n;i++) {

            if(a[i].first - a[i-1].first > maxDiff)
                cid++;

            pos[a[i].second] = i;
            comp[a[i].second] = cid;
        }

        vector<int> ans;

        for(auto &q : queries) {

            int u = q[0];
            int v = q[1];

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(
                abs(pos[u] - pos[v])
            );
        }

        return ans;
    }
};
