#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Maximize(vector<int>& arr) {
        // Sort the array in ascending order
        sort(arr.begin(), arr.end());

        // Initialize the result to store the maximum value
        long long result = 0;

        // Define a modulus value to prevent integer overflow
        int mod = 1000000007;

        // Iterate through the array and calculate the maximum sum
        for (int i = 0; i < arr.size(); i++) {
            result = (result + (long long) arr[i] * i) % mod;
        }

        // Return the result casted to an integer
        return (int) result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution sol;
        cout << sol.Maximize(arr) << endl;
    }
    return 0;
}