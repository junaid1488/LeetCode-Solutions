class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {

        const int MOD = 1e9 + 7;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        for(int i=0;i<nums.size();i++)
            pq.push({nums[i],i});

        while(k--) {
            auto [x,i] = pq.top();
            pq.pop();

            x *= m;
            pq.push({x,i});
        }

        vector<int> ans(nums.size());

        while(!pq.empty()) {
            auto [x,i] = pq.top();
            pq.pop();

            ans[i] = x % MOD;
        }

        return ans;
    }
};
