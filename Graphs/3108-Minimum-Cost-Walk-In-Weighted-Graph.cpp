class Solution {
public:

    vector<int> parent, sz;

    int find(int x) {
        return parent[x] == x
            ? x
            : parent[x] = find(parent[x]);
    }

    void unite(int a,int b) {

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b])
            swap(a,b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    vector<int> minimumCost(
        int n,
        vector<vector<int>>& edges,
        vector<vector<int>>& query
    ) {

        parent.resize(n);
        sz.assign(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;

        for(auto &e:edges)
            unite(e[0],e[1]);

        vector<int> compAND(n,-1);

        for(auto &e:edges){

            int root = find(e[0]);

            if(compAND[root]==-1)
                compAND[root]=e[2];
            else
                compAND[root]&=e[2];
        }

        vector<int> ans;

        for(auto &q:query){

            int s=q[0];
            int t=q[1];

            if(find(s)!=find(t))
                ans.push_back(-1);
            else
                ans.push_back(
                    compAND[find(s)]
                );
        }

        return ans;
    }
};
