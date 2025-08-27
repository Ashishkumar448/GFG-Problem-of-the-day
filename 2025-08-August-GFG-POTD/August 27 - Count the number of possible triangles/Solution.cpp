#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Step 1: sort
        int count = 0;

        // Fix the largest side
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            // Two pointer approach
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};
