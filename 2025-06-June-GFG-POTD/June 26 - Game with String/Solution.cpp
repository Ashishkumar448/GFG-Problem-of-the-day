#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int minValue(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0) {
                maxHeap.push(f);
            }
        }

        while (k > 0 && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            top--;
            k--;
            if (top > 0) {
                maxHeap.push(top);
            }
        }

        int result = 0;
        while (!maxHeap.empty()) {
            int f = maxHeap.top();
            maxHeap.pop();
            result += f * f;
        }

        return result;
    }
};
