class Solution {
public:
    int goodNodes(TreeNode* root, int mx = INT_MIN) {
        if(!root) return 0;

        int ans = (root->val >= mx);

        mx = max(mx, root->val);

        return ans +
               goodNodes(root->left, mx) +
               goodNodes(root->right, mx);
    }
};
