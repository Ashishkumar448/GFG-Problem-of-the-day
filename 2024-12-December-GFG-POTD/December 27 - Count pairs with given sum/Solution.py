#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        unordered_map<int, int> freqMap;  // Hash map to store frequencies of elements
        int count = 0;

        // Traverse the array
        for (int num : arr) {
            int complement = target - num;

            // If the complement is already in the map, increment the count
            if (freqMap.find(complement) != freqMap.end()) {
                count += freqMap[complement];
            }

            // Add the current number to the map
            freqMap[num]++;
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int target;
        cin >> target;

        Solution obj;
        cout << obj.countPairs(nums, target) << endl;
        cout << "~" << endl;
    }

    return 0;
}
