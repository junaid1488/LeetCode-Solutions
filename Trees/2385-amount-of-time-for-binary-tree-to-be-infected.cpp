class Solution {
public:
    unordered_map<int, vector<int>> graph;

    void build(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        build(node->left, node);
        build(node->right, node);
    }

    int amountOfTime(TreeNode* root, int start) {

        build(root, nullptr);

        queue<int> q;
        unordered_set<int> vis;

        q.push(start);
        vis.insert(start);

        int minutes = -1;

        while (!q.empty()) {

            int sz = q.size();
            minutes++;

            while (sz--) {

                int u = q.front();
                q.pop();

                for (int v : graph[u]) {

                    if (!vis.count(v)) {
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
        }

        return minutes;
    }
};
