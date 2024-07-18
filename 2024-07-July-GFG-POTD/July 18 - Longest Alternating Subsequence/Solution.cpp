#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LAS(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // Lengths of last increasing and decreasing subsequences
    int inc = 1;
    int dec = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            inc = dec + 1;
        } else if (arr[i] < arr[i - 1]) {
            dec = inc + 1;
        }
    }

    // The result is the maximum of inc and dec
    return max(inc, dec);
}

int main() {
    vector<int> arr = {1, 5, 4};
    cout << "Length of Longest Alternating Subsequence: " << LAS(arr) << endl;
    return 0;
}
