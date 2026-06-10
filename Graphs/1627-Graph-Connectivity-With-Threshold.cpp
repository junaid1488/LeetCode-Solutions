class Solution {
public:

    vector<int> parent, rank_;

    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(rank_[a] < rank_[b])
            swap(a, b);

        parent[b] = a;

        if(rank_[a] == rank_[b])
            rank_[a]++;
    }

    vector<bool> areConnected(
        int n,
        int threshold,
        vector<vector<int>>& queries
    ) {

        parent.resize(n + 1);
        rank_.assign(n + 1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(int d = threshold + 1; d <= n; d++) {

            for(int multiple = 2 * d;
                multiple <= n;
                multiple += d) {

                unite(d, multiple);
            }
        }

        vector<bool> ans;

        for(auto &q : queries) {

            ans.push_back(
                find(q[0]) == find(q[1])
            );
        }

        return ans;
    }
};
