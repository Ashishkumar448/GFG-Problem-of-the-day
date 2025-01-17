#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 1), right(n, 1), res(n);

        // Fill left product array
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * arr[i - 1];
        }

        // Fill right product array
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * arr[i + 1];
        }

        // Construct the result array
        for (int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string inputLine;
        cin.ignore();
        getline(cin, inputLine);

        vector<int> arr;
        int num;
        stringstream ss(inputLine);
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        vector<int> ans = ob.productExceptSelf(arr);

        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

