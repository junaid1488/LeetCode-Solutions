class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        const int MOD = 12345;

        int n = grid.size();
        int m = grid[0].size();
        int N = n * m;

        vector<long long> pre(N,1), suf(N,1);
        vector<int> a;

        for(auto &row : grid)
            for(int x : row)
                a.push_back(x % MOD);

        for(int i=1;i<N;i++)
            pre[i] = pre[i-1] * a[i-1] % MOD;

        for(int i=N-2;i>=0;i--)
            suf[i] = suf[i+1] * a[i+1] % MOD;

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i=0;i<N;i++)
            ans[i/m][i%m] =
                pre[i] * suf[i] % MOD;

        return ans;
    }
};
