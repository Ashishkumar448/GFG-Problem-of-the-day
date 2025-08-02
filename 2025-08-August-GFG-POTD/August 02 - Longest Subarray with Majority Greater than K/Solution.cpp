#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> transformed(n);

        // Step 1: Transform the array
        for (int i = 0; i < n; ++i) {
            transformed[i] = (arr[i] > k) ? 1 : -1;
        }

        // Step 2: Use prefix sum and hashmap
        unordered_map<int, int> firstIndex;
        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += transformed[i];

            if (prefixSum > 0) {
                maxLen = i + 1;
            } else {
                if (firstIndex.find(prefixSum) == firstIndex.end()) {
                    firstIndex[prefixSum] = i;
                }

                if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                    int prevIndex = firstIndex[prefixSum - 1];
                    maxLen = max(maxLen, i - prevIndex);
                }
            }
        }

        return maxLen;
    }
};
