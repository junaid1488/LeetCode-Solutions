class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> pal;

        for(int len = 1; len <= 15; len++) {
            int half = (len + 1) / 2;

            for(int x = (1 << (half - 1)); x < (1 << half); x++) {
                string s = bitset<16>(x).to_string();
                s = s.substr(s.find('1'));

                string t = s;
                for(int i = (len & 1 ? s.size() - 2 : s.size() - 1); i >= 0; i--)
                    t += s[i];

                pal.push_back(stoi(t, nullptr, 2));
            }
        }

        sort(pal.begin(), pal.end());

        vector<int> ans;

        for(int x : nums) {
            auto it = lower_bound(pal.begin(), pal.end(), x);

            int res = INT_MAX;

            if(it != pal.end()) res = min(res, abs(*it - x));
            if(it != pal.begin()) res = min(res, abs(*prev(it) - x));

            ans.push_back(res);
        }

        return ans;
    }
};
