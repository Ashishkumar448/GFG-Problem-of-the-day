#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> temp(n);

        // Convert array elements
        for (int i = 0; i < n; ++i) {
            temp[i] = (arr[i] > k) ? 1 : -1;
        }

        unordered_map<int, int> prefixMap;
        int prefixSum = 0, maxLength = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += temp[i];

            if (prefixSum > 0) {
                maxLength = i + 1;
            } else {
                if (prefixMap.find(prefixSum) == prefixMap.end()) {
                    prefixMap[prefixSum] = i;
                }
                if (prefixMap.find(prefixSum - 1) != prefixMap.end()) {
                    maxLength = max(maxLength, i - prefixMap[prefixSum - 1]);
                }
            }
        }

        return maxLength;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int x;
        while (ss >> x) {
            arr.push_back(x);
        }

        int k;
        cin >> k;
        cin.ignore();

        Solution sol;
        cout << sol.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
