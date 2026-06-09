class Solution {
public:
    const int MOD = 1e9 + 7;
    long long total = 0, ans = 0;

    long long sum(TreeNode* root) {
        if(!root) return 0;
        return root->val +
               sum(root->left) +
               sum(root->right);
    }

    long long dfs(TreeNode* root) {
        if(!root) return 0;

        long long s = root->val +
                      dfs(root->left) +
                      dfs(root->right);

        ans = max(ans, s * (total - s));

        return s;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);

        return ans % MOD;
    }
};
