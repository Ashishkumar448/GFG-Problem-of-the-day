#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return -1;
        int maxSum = arr[0] + arr[1];
        for (int i = 1; i < n - 1; i++) {
            maxSum = max(maxSum, arr[i] + arr[i + 1]);
        }
        return maxSum;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume the newline character after t

    while (t-- > 0) {
        string input;
        getline(cin, input);

        // Splitting the input into integers
        vector<int> arr;
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(arr);
        cout << res << endl;
    }

    return 0;
}
