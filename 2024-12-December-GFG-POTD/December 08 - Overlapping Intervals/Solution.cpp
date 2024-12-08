#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        // Step 1: Sort the intervals by the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        vector<int> currentInterval = intervals[0];
        merged.push_back(currentInterval);

        for (auto& interval : intervals) {
            int currentStart = currentInterval[0];
            int currentEnd = currentInterval[1];
            int nextStart = interval[0];
            int nextEnd = interval[1];

            // If intervals overlap, merge them
            if (currentEnd >= nextStart) {
                currentInterval[1] = max(currentEnd, nextEnd);
                merged.back()[1] = currentInterval[1];
            } else {
                // If they don't overlap, move to the next interval
                currentInterval = interval;
                merged.push_back(currentInterval);
            }
        }

        return merged;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);

        for (auto& interval : ans) {
            cout << interval[0] << " " << interval[1] << " ";
        }
        cout << endl;
    }
    return 0;
}

