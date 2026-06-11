class Solution {
    bool dfs(TreeNode* root, int val, string& path) {
        if(!root) return false;

        if(root->val == val) return true;

        path.push_back('L');
        if(dfs(root->left, val, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if(dfs(root->right, val, path))
            return true;
        path.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {

        string s, d;

        dfs(root, startValue, s);
        dfs(root, destValue, d);

        int i = 0;

        while(i < s.size() &&
              i < d.size() &&
              s[i] == d[i]) i++;

        return string(s.size() - i, 'U') + d.substr(i);
    }
};
