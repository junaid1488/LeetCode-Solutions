class Solution {
public:
    long long ans = 0;

    int dfs(int node, vector<int>& cost, int n) {

        if (node > n)
            return 0;

        int left = dfs(2 * node, cost, n);
        int right = dfs(2 * node + 1, cost, n);

        ans += abs(left - right);

        return cost[node - 1] + max(left, right);
    }

    int minIncrements(int n, vector<int>& cost) {

        dfs(1, cost, n);

        return ans;
    }
};
