class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int left = max(0, i - arr[i]);
                int right = min(n - 1, i + arr[i]);
                intervals.push_back({left, right});
            }
        }

        // Sort intervals
        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second > b.second;
             });

        int workers = 0;
        int curr = 0;
        int i = 0;

        // Greedy coverage
        while (curr < n) {
            int farthest = curr;

            while (i < intervals.size() && intervals[i].first <= curr) {
                farthest = max(farthest, intervals[i].second + 1);
                i++;
            }

            if (farthest == curr)
                return -1; // cannot extend coverage

            workers++;
            curr = farthest;
        }

        return workers;
    }
};
