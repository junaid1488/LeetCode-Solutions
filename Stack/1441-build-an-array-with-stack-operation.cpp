class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> ans;
        int j = 0;

        for(int i = 1; j < t.size(); i++) {
            ans.push_back("Push");
            if(i != t[j]) ans.push_back("Pop");
            else j++;
        }

        return ans;
    }
};
