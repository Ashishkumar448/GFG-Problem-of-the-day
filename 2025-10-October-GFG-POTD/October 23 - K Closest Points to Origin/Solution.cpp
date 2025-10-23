#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: stores {distance, index}
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y; // distance squared

            maxHeap.push({dist, i});
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove farthest point
            }
        }

        // Collect k closest points
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int idx = maxHeap.top().second;
            maxHeap.pop();
            result.push_back(points[idx]);
        }

        return result;
    }
};
