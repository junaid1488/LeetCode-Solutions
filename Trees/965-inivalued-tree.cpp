class Solution {
public:
    bool dfs(TreeNode* node, int val) {
        if (!node) return true;

        if (node->val != val)
            return false;

        return dfs(node->left, val) &&
               dfs(node->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};
