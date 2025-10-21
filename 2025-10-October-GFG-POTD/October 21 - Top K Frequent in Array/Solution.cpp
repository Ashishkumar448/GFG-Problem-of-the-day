#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        // Step 1: Count frequency of each element
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Create a max-heap with custom comparator
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;  // higher number first if freq same
            return a.second < b.second;    // higher frequency first
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        // Step 3: Push all elements into PQ
        for (auto& it : freqMap) {
            pq.push({it.first, it.second});
        }

        // Step 4: Extract top k elements
        vector<int> result;
        for (int i = 0; i < k && !pq.empty(); i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
