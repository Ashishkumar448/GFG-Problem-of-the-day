#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap; // Map to store prefix sums and their indices
        int prefixSum = 0;
        int maxLength = 0;

        // Iterate through the array
        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i]; // Update prefix sum

            // Check if prefixSum equals k
            if (prefixSum == k) {
                maxLength = i + 1; // Update maxLength for the entire array up to this point
            }

            // Check if (prefixSum - k) exists in the map
            if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
                // Calculate the length of the subarray and update maxLength
                maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
            }

            // Store prefixSum in the map if not already present
            if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the array
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int k;
        cin >> k; // Target sum

        Solution ob;
        cout << ob.longestSubarray(nums, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
