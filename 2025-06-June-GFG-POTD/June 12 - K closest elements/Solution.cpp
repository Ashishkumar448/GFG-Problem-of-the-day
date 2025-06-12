#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> printKClosest(vector<int>& arr, int k, int x) {
        // Max heap using custom comparator
        priority_queue<pair<int, int>> maxHeap;

        for (int val : arr) {
            if (val == x) continue;
            int dist = abs(val - x);
            maxHeap.push({dist, -val});  // Store -val to simulate preferring larger value on tie

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(-maxHeap.top().second);  // Negate to get original value
            maxHeap.pop();
        }

        // Sort by closeness and prefer larger on tie
        sort(result.begin(), result.end(), [&](int a, int b) {
            int distA = abs(a - x);
            int distB = abs(b - x);
            if (distA == distB) return a > b;
            return distA < distB;
        });

        return result;
    }
};
