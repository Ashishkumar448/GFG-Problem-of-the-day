#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int required = (n + 1) / 2; // ceil(n / 2)
        int luckyCount = 0;
        vector<int> addList;

        for (int num : arr) {
            if (num % k == 0) {
                luckyCount++;
            } else {
                addList.push_back(k - (num % k));
            }
        }

        if (luckyCount >= required) {
            return 0;
        }

        sort(addList.begin(), addList.end());

        int soldiersNeeded = 0;
        int toMakeLucky = required - luckyCount;

        for (int i = 0; i < toMakeLucky; i++) {
            soldiersNeeded += addList[i];
        }

        return soldiersNeeded;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 5, 6, 7, 9, 10};
    int k = 4;
    cout << sol.minSoldiers(arr, k) << endl; // Output: 4
    return 0;
}
