#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> minDeque, maxDeque;
        
        int left = 0, bestLen = 0, bestStart = 0;
        
        for (int right = 0; right < n; right++) {
            // Maintain decreasing deque for max
            while (!maxDeque.empty() && arr[maxDeque.back()] < arr[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            
            // Maintain increasing deque for min
            while (!minDeque.empty() && arr[minDeque.back()] > arr[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            
            // Shrink window if difference exceeds x
            while (arr[maxDeque.front()] - arr[minDeque.front()] > x) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                left++;
            }
            
            // Update best window
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
        }
        
        vector<int> result;
        for (int i = bestStart; i < bestStart + bestLen; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};
