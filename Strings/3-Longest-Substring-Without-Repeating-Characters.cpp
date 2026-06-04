class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right])) {
                left = max(left, mp[s[right]] + 1);
            }
// right & left are the array index//
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
