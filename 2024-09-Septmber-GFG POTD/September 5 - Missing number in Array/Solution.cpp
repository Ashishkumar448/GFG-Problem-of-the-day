#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the missing number in the array
    int missingNumber(int n, vector<int>& arr) {
        // Calculate the expected sum of the first n natural numbers
        int totalSum = n * (n + 1) / 2;

        // Calculate the sum of elements in the array
        int currentSum = 0;
        for (int num : arr) {
            currentSum += num;
        }

        // The missing number is the difference
        return totalSum - currentSum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> arr[i];
        }
        Solution sln;
        cout << sln.missingNumber(n, arr) << endl;
    }
    return 0;
}
