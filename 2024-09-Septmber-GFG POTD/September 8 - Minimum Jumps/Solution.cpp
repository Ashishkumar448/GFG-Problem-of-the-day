// C++ implementation of the minimum jumps problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Edge case: If the array length is 1, no jumps are needed.
        if (arr.size() == 1) {
            return 0;
        }

        // If the first element is 0, you can't move anywhere.
        if (arr[0] == 0) {
            return -1;
        }

        // Initialize variables
        int maxReach = arr[0]; // The farthest point that can be reached.
        int steps = arr[0];    // Steps that can be taken with the current jump.
        int jumps = 1;         // Number of jumps made.

        // Start traversing the array
        for (int i = 1; i < arr.size(); i++) {
            // Check if we have reached the last element.
            if (i == arr.size() - 1) {
                return jumps;
            }

            // Update the farthest point that can be reached.
            maxReach = max(maxReach, i + arr[i]);

            // Use a step to move forward.
            steps--;

            // If no steps are remaining
            if (steps == 0) {
                // We must have used a jump.
                jumps++;

                // If the current index is beyond the maximum reach, return -1.
                if (i >= maxReach) {
                    return -1;
                }

                // Reinitialize steps with the amount of steps to reach maxReach from position i.
                steps = maxReach - i;
            }
        }

        // If we haven't returned inside the loop, it's impossible to reach the end.
        return -1;
    }
};

// Driver code to read input and print output
int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin.ignore(); // to clear the input buffer
        getline(cin, line);

        // Parse input into an array
        vector<int> arr;
        stringstream ss(line);
        string token;
        while (ss >> token) {
            arr.push_back(stoi(token));
        }

        // Create an instance of the Solution class and call minJumps
        Solution solution;
        cout << solution.minJumps(arr) << endl;
    }
    return 0;
}
