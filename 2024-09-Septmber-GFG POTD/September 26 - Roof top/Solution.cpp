#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the maximum number of consecutive steps
    // where we see an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int maxSteps = 0; // Variable to keep track of maximum steps
        int currentSteps = 0; // Variable to count current consecutive steps

        // Traverse through the array of building heights
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                currentSteps++; // Increment if the current building is taller
                maxSteps = max(maxSteps, currentSteps); // Update maxSteps
            } else {
                currentSteps = 0; // Reset if no increase in height
            }
        }

        return maxSteps;
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Number of buildings
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Input building heights
        }

        Solution sol;
        cout << sol.maxStep(arr) << endl; // Output the result
    }
    return 0;
}
