class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        int n = fc.size();
        vector<unordered_set<string>> s(n);
        
        for(int i = 0; i < n; i++)
            s[i] = unordered_set<string>(fc[i].begin(), fc[i].end());

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            bool subset = false;

            for(int j = 0; j < n && !subset; j++) {
                if(i == j || s[i].size() > s[j].size()) continue;

                subset = all_of(s[i].begin(), s[i].end(),
                    [&](string c){ return s[j].count(c); });
            }

            if(!subset) ans.push_back(i);
        }

        return ans;
    }
};
