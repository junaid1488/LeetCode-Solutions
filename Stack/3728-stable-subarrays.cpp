class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        long long ans = 0;

        vector<long long> pre(n + 1);
        for(int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + capacity[i];

        map<pair<long long,long long>, vector<int>> mp;

        for(int r = 0; r < n; r++) {

            auto key = make_pair(
                (long long)capacity[r],
                pre[r] - capacity[r]
            );

            if(mp.count(key)) {
                auto &v = mp[key];

                ans += upper_bound(
                    v.begin(), v.end(), r - 2
                ) - v.begin();
            }

            mp[{(long long)capacity[r], pre[r]}].push_back(r);
        }

        return ans;
    }
};
