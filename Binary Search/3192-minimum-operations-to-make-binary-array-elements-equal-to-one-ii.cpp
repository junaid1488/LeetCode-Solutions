class Solution {
public:
    int minOperations(vector<int>& nums) {

        int flip = 0;
        int ans = 0;

        for(int x : nums) {

            if((x ^ flip) == 0) {
                ans++;
                flip ^= 1;
            }
        }

        return ans;
    }
};
