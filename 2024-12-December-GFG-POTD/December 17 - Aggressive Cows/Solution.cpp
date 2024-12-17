#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int k) {
        // Sort the stall positions to facilitate binary search
        sort(stalls.begin(), stalls.end());

        // Define the binary search range
        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls.front(); // Maximum possible distance
        int result = 0;

        // Binary search to find the largest minimum distance
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Update result if cows can be placed
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }
        return result;
    }

private:
    bool canPlaceCows(vector<int>& stalls, int k, int distance) {
        int count = 1; // Place the first cow in the first stall
        int lastPlacedCow = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPlacedCow >= distance) {
                count++;
                lastPlacedCow = stalls[i];
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        int k;
        cin >> k;

        Solution obj;
        cout << obj.aggressiveCows(stalls, k) << endl;
    }
    return 0;
}
