class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1'000'000'007;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 0
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
