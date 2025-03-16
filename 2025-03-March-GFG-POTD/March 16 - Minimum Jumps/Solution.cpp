#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;  // Already at the last index
        if (arr[0] == 0) return -1; // Can't move forward

        int maxReach = arr[0]; // The farthest index we can reach
        int steps = arr[0];    // Steps we can still take
        int jumps = 1;         // Initial jump count

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps; // Reached the end

            maxReach = max(maxReach, i + arr[i]); // Update maxReach
            steps--; // Use a step

            if (steps == 0) { // Need to jump
                jumps++;
                if (i >= maxReach) return -1; // Can't reach further
                steps = maxReach - i; // Refill steps
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) arr.push_back(num);

        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}
