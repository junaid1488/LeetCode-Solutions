class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {

        int ans = 0;

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 1, 1});

        while(!q.empty()) {

            auto [node, parent, grandparent] = q.front();
            q.pop();

            if(grandparent % 2 == 0)
                ans += node->val;

            if(node->left)
                q.push({node->left, node->val, parent});

            if(node->right)
                q.push({node->right, node->val, parent});
        }

        return ans;
    }
};
