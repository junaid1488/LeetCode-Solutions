class Solution {
public:
    vector<vector<long long>> seg;
    vector<long long> rankVal;
    int n;

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = {rankVal[l]};
            return;
        }

        int mid = (l + r) >> 1;

        build(idx << 1, l, mid);
        build(idx << 1 | 1, mid + 1, r);

        auto &a = seg[idx << 1];
        auto &b = seg[idx << 1 | 1];

        seg[idx].resize(a.size() + b.size());

        merge(a.begin(), a.end(),
              b.begin(), b.end(),
              seg[idx].begin());
    }

    int query(int idx, int l, int r,
              int ql, int qr,
              long long x) {

        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr) {
            return upper_bound(
                       seg[idx].begin(),
                       seg[idx].end(),
                       x
                   ) - seg[idx].begin();
        }

        int mid = (l + r) >> 1;

        return query(idx << 1, l, mid, ql, qr, x) +
               query(idx << 1 | 1, mid + 1, r, ql, qr, x);
    }

    vector<long long> kthSmallestRemainingEven(
        vector<int>& nums,
        vector<vector<int>>& queries) {

        n = nums.size();

        rankVal.resize(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                rankVal[i] = nums[i] / 2LL;
            else
                rankVal[i] = (long long)4e18; // ignore odds
        }

        seg.resize(4 * n);
        build(1, 0, n - 1);

        vector<long long> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];
            long long k = q[2];

            int removed =
                query(1, 0, n - 1, l, r, (long long)4e18);

            long long lo = 1;
            long long hi = k + removed;

            while (lo < hi) {

                long long mid = (lo + hi) >> 1;

                long long cntRemoved =
                    query(1, 0, n - 1, l, r, mid);

                long long remaining =
                    mid - cntRemoved;

                if (remaining >= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans.push_back(2LL * lo);
        }

        return ans;
    }
};
