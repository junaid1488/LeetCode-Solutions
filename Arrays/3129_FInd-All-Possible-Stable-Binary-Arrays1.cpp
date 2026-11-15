class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1'000'000'007;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 0
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 1

        // Base cases: only zeros or only ones => only one string if len <= min(limit, zero/one)
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;

        // DP iterations
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) 
