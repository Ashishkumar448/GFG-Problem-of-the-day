#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr) {
        int n = arr.size();
        // Handle edge cases
        if (n == 1) return 0;

        // Check for peak elements at the beginning and end
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        // Iterate through the array from index 1 to n-2
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
                return i;
            }
        }

        return -1; // No peak element found
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
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        Solution obj;
        int idx = obj.peakElement(a);
        int n = a.size();
        bool f = false;

        if (idx < 0 || idx >= n) {
            cout << "false" << endl;
        } else {
            if (n == 1 && idx == 0) {
                f = true;
            } else if (idx == 0 && a[0] > a[1]) {
                f = true;
            } else if (idx == n - 1 && a[n - 1] > a[n - 2]) {
                f = true;
            } else if (idx > 0 && idx < n && a[idx] > a[idx + 1] && a[idx] > a[idx - 1]) {
                f = true;
            }
            cout << (f ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
