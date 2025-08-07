#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDifference(vector<string>& arr) {
        int n = arr.size();
        vector<int> seconds(n);

        // Convert time strings to seconds
        for (int i = 0; i < n; i++) {
            int h = stoi(arr[i].substr(0, 2));
            int m = stoi(arr[i].substr(3, 2));
            int s = stoi(arr[i].substr(6, 2));
            seconds[i] = h * 3600 + m * 60 + s;
        }

        // Sort the seconds array
        sort(seconds.begin(), seconds.end());

        int minDiff = INT_MAX;

        // Compute difference between adjacent times
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }

        // Handle wrap-around at midnight
        int dayInSeconds = 24 * 3600;
        int wrapAroundDiff = dayInSeconds - seconds[n - 1] + seconds[0];
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};
