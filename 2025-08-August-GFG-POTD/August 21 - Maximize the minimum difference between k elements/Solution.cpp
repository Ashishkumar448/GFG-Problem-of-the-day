#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 0, high = arr[n - 1] - arr[0], ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(arr, k, mid)) {
                ans = mid;     // mid is possible, try larger
                low = mid + 1;
            } else {
                high = mid - 1; // too large, reduce
            }
        }
        return ans;
    }

private:
    bool canPlace(vector<int>& arr, int k, int dist) {
        int count = 1;  // pick first element
        int last = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) {
                count++;
                last = arr[i];
                if (count >= k) return true;
            }
        }
        return false;
    }
};
