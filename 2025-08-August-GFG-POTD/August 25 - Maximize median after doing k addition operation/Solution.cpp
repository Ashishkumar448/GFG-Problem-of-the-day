#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // check if we can make the median at least 'target' using at most 'k' operations
    bool isPossible(vector<int>& arr, int target, long long k) {
        int n = arr.size();

        if (n % 2 == 1) {
            // odd-sized array → consider elements from middle to end
            for (int i = n / 2; i < n; ++i) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) break;
            }
        } else {
            // even-sized array → handle two middle elements separately
            if (arr[n / 2] <= target) {
                k -= (target - arr[n / 2]);
                k -= (target - arr[n / 2 - 1]);
            } else {
                k -= (2 * target - (arr[n / 2] + arr[n / 2 - 1]));
            }
            // process remaining elements to the right
            for (int i = n / 2 + 1; i < n; ++i) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) break;
            }
        }
        return k >= 0;
    }

    int maximizeMedian(vector<int>& arr, long long k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // compute initial median (floor if even length)
        int iniMedian = arr[n / 2];
        if (n % 2 == 0) {
            iniMedian += arr[n / 2 - 1];
            iniMedian /= 2;
        }

        long long low = iniMedian, high = iniMedian + k;
        int bestMedian = iniMedian;

        // binary search to find maximum achievable median
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (isPossible(arr, mid, k)) {
                bestMedian = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return bestMedian;
    }
};
