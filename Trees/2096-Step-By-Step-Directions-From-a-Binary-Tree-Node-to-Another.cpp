class Solution {
public:
    bool findPath(TreeNode* root, int target, string& path) {

        if (!root) return false;

        if (root->val == target)
            return true;

        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root,
                         int startValue,
                         int destValue) {

        string startPath, destPath;

        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int i = 0;

        while (i < startPath.size() &&
               i < destPath.size() &&
               startPath[i] == destPath[i]) {
            i++;
        }

        string ans(startPath.size() - i, 'U');

        ans += destPath.substr(i);

        return ans;
    }
};
