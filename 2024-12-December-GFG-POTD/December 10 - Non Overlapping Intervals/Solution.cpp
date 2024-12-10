#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<vector<int>>& intervals) {
        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0; // Count of intervals to remove
        int prevEnd = INT_MIN; // End of the last added interval

        for (auto& interval : intervals) {
            // If the current interval starts before the previous one ends, overlap occurs
            if (interval[0] < prevEnd) {
                count++;
            } else {
                // Update the end to the current interval's end
                prevEnd = interval[1];
            }
        }

        return count;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        int ans = obj.minRemoval(intervals);
        cout << ans << endl;
    }
    return 0;
}
