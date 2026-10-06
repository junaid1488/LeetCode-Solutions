class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> freq(1001, 0);

        for (auto &arr : nums) {
            for (int x : arr) {
                freq[x]++;
            }
        }
//frequency denotes precedence//
        vector<int> ans;

    

        return ans;
    }
};
