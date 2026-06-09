class Solution {
public:
    int minProcessingTime(vector<int>& processorTime,
                          vector<int>& tasks) {

        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());

        int ans = 0;

        for(int i = 0; i < processorTime.size(); i++)
            ans = max(ans,
                      processorTime[i] + tasks[4 * i]);

        return ans;
    }
};
