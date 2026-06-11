class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {

        int ones = accumulate(nums.begin(), nums.end(), 0);
        int zeros = 0;

        int mx = -1;
        vector<int> ans;

        for(int i = 0; i <= nums.size(); i++) {

            int score = zeros + ones;

            if(score > mx) {
                mx = score;
                ans = {i};
            }
            else if(score == mx) {
                ans.push_back(i);
            }

            if(i < nums.size()) {
                if(nums[i] == 0) zeros++;
                else ones--;
            }
        }

        return ans;
    }
};
