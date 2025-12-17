#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> result;
        
        // Edge case
        if (arr.empty()) return result;

        // Sort intervals by starting time
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int start = arr[0][0];
        int end = arr[0][1];

        for (int i = 1; i < arr.size(); i++) {
            // Overlapping intervals
            if (arr[i][0] <= end) {
                end = max(end, arr[i][1]);
            } else {
                // No overlap
                result.push_back({start, end});
                start = arr[i][0];
                end = arr[i][1];
            }
        }

        // Add last interval
        result.push_back({start, end});

        return result;
    }
};
