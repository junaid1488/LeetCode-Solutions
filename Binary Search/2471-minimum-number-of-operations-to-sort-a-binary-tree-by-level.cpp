class Solution {
    int minSwap(vector<int>& v) {
        int n = v.size(), ans = 0;

        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({v[i], i});

        sort(a.begin(), a.end());

        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(vis[i] || a[i].second == i) continue;

            int len = 0, j = i;

            while(!vis[j]) {
                vis[j] = true;
                j = a[j].second;
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while(sz--) {
                auto cur = q.front();
                q.pop();

                level.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            ans += minSwap(level);
        }

        return ans;
    }
};
