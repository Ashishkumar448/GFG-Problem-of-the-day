#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        // STEP 1: Find repeating using index marking
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;

            if (arr[idx] < 0) {
                repeating = abs(arr[i]);
            } else {
                arr[idx] = -arr[idx];
            }
        }

        // STEP 2: Find missing
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {repeating, missing};
    }
};
