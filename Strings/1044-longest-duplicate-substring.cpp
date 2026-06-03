class Solution {
public:
    string s;
    int n;
    
    int search(int len) {
        long long mod = 1000000007;
        long long base = 31;

        long long hash = 0;
        long long power = 1;

        for (int i = 0; i < len; i++) {
            hash = (hash * base + (s[i] - 'a' + 1)) % mod;

            if (i < len - 1)
                power = (power * base) % mod;
        }

        unordered_map<long long, vector<int>> mp;
        mp[hash].push_back(0);

        for (int i = len; i < n; i++) {
            hash = (hash - (s[i - len] - 'a' + 1) * power % mod + mod) % mod;
            hash = (hash * base + (s[i] - 'a' + 1)) % mod;

            int start = i - len + 1;

            if (mp.count(hash)) {
                string cur = s.substr(start, len);

                for (int prev : mp[hash]) {
                    if (s.compare(prev, len, cur) == 0)
                        return start;
                }
            }

            mp[hash].push_back(start);
        }

        return -1;
    }

    string longestDupSubstring(string str) {
        s = str;
        n = s.size();

        int left = 1, right = n - 1;
        int start = -1, maxLen = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int idx = search(mid);

            if (idx != -1) {
                start = idx;
                maxLen = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return start == -1 ? "" : s.substr(start, maxLen);
    }
};
