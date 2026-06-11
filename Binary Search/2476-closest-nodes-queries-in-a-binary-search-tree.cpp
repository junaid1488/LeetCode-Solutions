class Solution {
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inorder(root, v);

        vector<vector<int>> ans;

        for(int q : queries){
            auto lo = lower_bound(v.begin(), v.end(), q);
            auto up = upper_bound(v.begin(), v.end(), q);

            int mn = (up == v.begin()) ? -1 : *prev(up);
            int mx = (lo == v.end()) ? -1 : *lo;

            ans.push_back({mn, mx});
        }

        return ans;
    }
};
