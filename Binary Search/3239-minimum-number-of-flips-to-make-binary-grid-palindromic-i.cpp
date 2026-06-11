class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int row = 0, col = 0;

        for(int i = 0; i < m; i++) {
            int l = 0, r = n - 1;

            while(l < r) {
                row += (grid[i][l] != grid[i][r]);
                l++;
                r--;
            }
        }

        for(int j = 0; j < n; j++) {
            int l = 0, r = m - 1;

            while(l < r) {
                col += (grid[l][j] != grid[r][j]);
                l++;
                r--;
            }
        }

        return min(row, col);
    }
};
