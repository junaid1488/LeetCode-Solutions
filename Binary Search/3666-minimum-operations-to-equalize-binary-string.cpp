class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int z = count(s.begin(), s.end(), '0');

        if(z == 0) return 0;
        if(k == n) return (z == n ? 1 : -1);

        long long ans = LLONG_MAX;
        long long d = n - k;

        auto ceilDiv = [](long long a, long long b) {
            return (a + b - 1) / b;
        };

        if(z % 2 == 0) {
            long long t = max(ceilDiv(z, k), ceilDiv(z, d));
            if(t & 1) t++;
            ans = min(ans, t);
        }

        if((z & 1) == (k & 1)) {
            long long t = max(ceilDiv(z, k), ceilDiv(n - z, d));
            if(!(t & 1)) t++;
            ans = min(ans, t);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
