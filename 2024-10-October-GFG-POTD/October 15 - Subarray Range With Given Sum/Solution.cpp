#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Map to store the frequency of prefix sums
        unordered_map<int, int> prefixSumMap;
        int count = 0;
        int prefixSum = 0;

        // To account for the case when the subarray starts from index 0
        prefixSumMap[0] = 1;

        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            // Calculate the running prefix sum
            prefixSum += arr[i];

            // Check if prefixSum - target exists in the map
            if (prefixSumMap.find(prefixSum - tar) != prefixSumMap.end()) {
                // If yes, add the count of occurrences of (prefixSum - target) to the result
                count += prefixSumMap[prefixSum - tar];
            }

            // Update the frequency of the current prefix sum in the map
            prefixSumMap[prefixSum]++;
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        string line;
        cin.ignore(); // Ignore the newline from the previous input
        getline(cin, line);

        // Split the line into tokens and convert to integers
        vector<int> array;
        int num;
        stringstream ss(line);
        while (ss >> num) {
            array.push_back(num);
        }

        int tar;
        cin >> tar;

        Solution obj;
        int res = obj.subArraySum(array, tar);

        cout << res << endl;
    }

    return 0;
}
