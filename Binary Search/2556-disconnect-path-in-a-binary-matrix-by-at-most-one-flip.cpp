class Solution {
    bool dfs(vector<vector<int>>& g, int i, int j) {
        int m = g.size(), n = g[0].size();

        if(i >= m || j >= n || g[i][j] == 0)
            return false;

        if(i == m - 1 && j == n - 1)
            return true;

        g[i][j] = 0;

        return dfs(g, i + 1, j) ||
               dfs(g, i, j + 1);
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {

        if(!dfs(grid, 0, 0))
            return true;

        grid[0][0] = 1;
        grid.back().back() = 1;

        return !dfs(grid, 0, 0);
    }
};
