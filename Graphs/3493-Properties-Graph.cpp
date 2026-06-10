class Solution {
public:

    vector<int> parent, sz;

    int find(int x) {
        return parent[x] == x
            ? x
            : parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int numberOfComponents(
        vector<vector<int>>& properties,
        int k) {

        int n = properties.size();

        parent.resize(n);
        sz.assign(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        vector<unordered_set<int>> sets(n);

        for(int i = 0; i < n; i++) {
            for(int x : properties[i])
                sets[i].insert(x);
        }

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int common = 0;

                if(sets[i].size() > sets[j].size())
                    swap(sets[i], sets[j]);

                for(int x : sets[i]) {

                    if(sets[j].count(x)) {

                        common++;

                        if(common >= k) {
                            unite(i, j);
                            break;
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(find(i) == i)
                ans++;
        }

        return ans;
    }
};
