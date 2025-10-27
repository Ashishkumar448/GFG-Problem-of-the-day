#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> result;
        if (arr1.empty() || arr2.empty() || k == 0)
            return result;

        // Min-heap storing {sum, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Initialize heap with first element from arr2 for each arr1[i]
        for (int i = 0; i < min((int)arr1.size(), k); i++) {
            minHeap.push({arr1[i] + arr2[0], i, 0});
        }

        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top[1], j = top[2];

            result.push_back({arr1[i], arr2[j]});

            // Push next pair from arr2
            if (j + 1 < arr2.size()) {
                minHeap.push({arr1[i] + arr2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};
