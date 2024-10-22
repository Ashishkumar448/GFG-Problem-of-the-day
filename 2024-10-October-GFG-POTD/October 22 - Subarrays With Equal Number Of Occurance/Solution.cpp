#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // Map to store the count of balances
        unordered_map<int, int> balanceMap;
        balanceMap[0] = 1;  // Initialize with balance 0 occurring once (for empty subarray)

        int balance = 0;
        int result = 0;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {
            // Update balance based on x, y, or other numbers
            if (arr[i] == x) {
                balance += 1;  // Increment balance for x
            } else if (arr[i] == y) {
                balance -= 1;  // Decrement balance for y
            }

            // If the same balance occurred before, it means we found subarrays
            // with the same occurrence of x and y
            result += balanceMap[balance];

            // Update the balanceMap with the current balance
            balanceMap[balance]++;
        }

        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t-- > 0) {
        vector<int> arr;
        string line;
        cin.ignore();  // To ignore the newline character from previous input
        getline(cin, line);
        
        // Parse the input line into integers
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int x, y;
        cin >> x >> y;

        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << endl;
    }

    return 0;
}
