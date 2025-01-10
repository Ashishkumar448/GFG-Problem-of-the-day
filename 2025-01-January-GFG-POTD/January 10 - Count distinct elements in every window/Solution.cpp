#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(int arr[], int n, int k) {
        vector<int> result;
        unordered_map<int, int> freqMap;

        // Process the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size());

        // Slide the window
        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            int outgoing = arr[i - k];
            freqMap[outgoing]--;
            if (freqMap[outgoing] == 0) {
                freqMap.erase(outgoing);
            }

            // Add the element coming into the window
            int incoming = arr[i];
            freqMap[incoming]++;

            // Add the size of the map (distinct count) to the result
            result.push_back(freqMap.size());
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;

        Solution obj;
        vector<int> ans = obj.countDistinct(arr, n, k);
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
