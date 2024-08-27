#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMaxDiff(vector<int>& arr) {
        int n = arr.size();

        // Arrays to store the nearest smaller elements on the left and right
        vector<int> leftSmaller(n, 0);
        vector<int> rightSmaller(n, 0);

        // Fill the leftSmaller array
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            leftSmaller[i] = (s.empty()) ? 0 : s.top();
            s.push(arr[i]);
        }

        // Clear the stack and fill the rightSmaller array
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            rightSmaller[i] = (s.empty()) ? 0 : s.top();
            s.push(arr[i]);
        }

        // Find the maximum absolute difference
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(leftSmaller[i] - rightSmaller[i]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }

        return maxDiff;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin.ignore(); // To ignore the newline character after integer input
        getline(cin, input);
        vector<int> arr;
        stringstream ss(input);
        int temp;
        while (ss >> temp) {
            arr.push_back(temp);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}
