#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);

        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int minVal = min(smallest, arr[i + 1] - k);
            int maxVal = max(largest, arr[i] + k);

            if (minVal < 0) continue; // skip invalid cases

            ans = min(ans, maxVal - minVal);
        }

        return ans;
    }
};
