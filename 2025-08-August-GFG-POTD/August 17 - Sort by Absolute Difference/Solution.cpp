#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rearrange(vector<int>& arr, int x) {
        // Use stable_sort to preserve the original order in case of ties
        stable_sort(arr.begin(), arr.end(), [&](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 5, 3, 9, 2};
    int x = 7;
    sol.rearrange(arr, x);

    for (int num : arr) cout << num << " ";
    return 0;
}
