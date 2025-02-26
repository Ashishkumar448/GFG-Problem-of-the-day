#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n), result(n + 1, 0);
        stack<int> s;

        // Finding previous smaller element
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        // Clear stack for next calculation
        while (!s.empty()) s.pop();

        // Finding next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        // Fill the result array based on window sizes
        for (int i = 0; i < n; i++) {
            int windowSize = left[i] + right[i] - 1;
            result[windowSize] = max(result[windowSize], arr[i]);
        }

        // Fill remaining values to propagate the max values
        for (int i = n - 1; i >= 1; i--) {
            result[i] = max(result[i], result[i + 1]);
        }

        // Prepare final output
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(result[i]);
        }
        return ans;
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
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution solution;
        vector<int> result = solution.maxOfMins(arr);
        for (int val : result) {
            cout << val << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
