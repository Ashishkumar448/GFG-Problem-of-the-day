#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0, count = 0;

        // Initialize the prefix sum count with 0 sum
        prefixSumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;

            // Check if there exists a prefix sum such that currentSum - prefixSum = k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Update the frequency of the current prefix sum in the map
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        string line;
        cin.ignore();
        getline(cin, line);
        vector<int> arr;
        int num;

        // Parse the input into a vector of integers
        stringstream ss(line);
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution sol;
        int res = sol.countSubarrays(arr, k);

        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
