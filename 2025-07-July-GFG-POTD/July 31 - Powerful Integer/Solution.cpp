#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> mp;

        // Mark start and end+1
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            mp[start]++;
            mp[end + 1]--;
        }

        int curr = 0;
        int lastPoint = -1;
        int maxPowerful = -1;

        for (auto& [point, value] : mp) {
            if (curr >= k && lastPoint != -1) {
                maxPowerful = max(maxPowerful, point - 1);
            }
            curr += value;
            lastPoint = point;
        }

        return maxPowerful;
    }
};
