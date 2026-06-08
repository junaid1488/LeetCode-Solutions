class Solution {
public:
    bool validateBinaryTreeNodes(int n,
                                 vector<int>& leftChild,
                                 vector<int>& rightChild) {

        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {

            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1)
                    return false;
            }

            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1)
                    return false;
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {

                if (root != -1)
                    return false;

                root = i;
            }
        }

        if (root == -1)
            return false;

        vector<bool> vis(n, false);

        function<bool(int)> dfs = [&](int node) {

            if (node == -1)
                return true;

            if (vis[node])
                return false;

            vis[node] = true;

            return dfs(leftChild[node]) &&
                   dfs(rightChild[node]);
        };

        if (!dfs(root))
            return false;

        return count(vis.begin(), vis.end(), true) == n;
    }
};
