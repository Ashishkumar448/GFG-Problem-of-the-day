#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        map<int, set<int>> groups; // freq -> set of values

        auto addElement = [&](int x) {
            int oldCount = freq[x];
            int newCount = oldCount + 1;
            freq[x] = newCount;

            if (oldCount > 0) {
                auto &s = groups[oldCount];
                s.erase(x);
                if (s.empty()) groups.erase(oldCount);
            }
            groups[newCount].insert(x);
        };

        auto removeElement = [&](int x) {
            int oldCount = freq[x];
            int newCount = oldCount - 1;

            auto &s = groups[oldCount];
            s.erase(x);
            if (s.empty()) groups.erase(oldCount);

            if (newCount == 0) {
                freq.erase(x);
            } else {
                freq[x] = newCount;
                groups[newCount].insert(x);
            }
        };

        int sum = 0;

        // build first window
        for (int i = 0; i < k; i++) {
            addElement(arr[i]);
        }

        // process windows
        for (int i = k; i <= n; i++) {
            int maxFreq = groups.rbegin()->first;
            int mode = *groups[maxFreq].begin(); // smallest element
            sum += mode;

            if (i < n) {
                removeElement(arr[i - k]);
                addElement(arr[i]);
            }
        }

        return sum;
    }
};
