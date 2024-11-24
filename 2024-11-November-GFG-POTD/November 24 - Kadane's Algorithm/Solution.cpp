#include <iostream>
#include <vector>
#include <algorithm> // For max function
using namespace std;

class Solution {
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int>& arr) {
        int maxSum = INT_MIN;  // Initialize to the smallest integer value
        int currentSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            maxSum = max(maxSum, currentSum);
            
            // If currentSum is negative, reset to 0
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};

// Driver code
int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        cout << obj.maxSubarraySum(arr) << endl;
    }
    return 0;
}
