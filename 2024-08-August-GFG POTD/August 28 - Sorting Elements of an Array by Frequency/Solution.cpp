#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Step 1: Count frequencies
        unordered_map<int, int> frequencyMap;
        for (int num : arr) {
            frequencyMap[num]++;
        }

        // Step 2: Create a list of pairs
        vector<pair<int, int>> freqList;
        for (auto& entry : frequencyMap) {
            freqList.push_back({entry.first, entry.second});
        }

        // Step 3: Sort the list
        sort(freqList.begin(), freqList.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (b.second != a.second) {
                return b.second < a.second; // Sort by frequency in descending order
            } else {
                return a.first < b.first; // If frequency is the same, sort by number in ascending order
            }
        });

        // Step 4: Build the result
        vector<int> result;
        for (auto& pair : freqList) {
            for (int i = 0; i < pair.second; i++) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;
    while (n--) {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        Solution sol;
        vector<int> ans = sol.sortByFreq(arr);
        for (int num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
