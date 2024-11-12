#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttend(vector<vector<int>>& arr) {
        // Sort meetings by start time
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Check for any overlaps
        for (int i = 1; i < arr.size(); i++) {
            // If current meeting starts before the previous one ends, return false
            if (arr[i][0] < arr[i - 1][1]) {
                return false;
            }
        }
        // No overlaps found, return true
        return true;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }
        Solution obj;
        bool ans = obj.canAttend(arr);
        cout << (ans ? "true" : "false") << endl;
    }
    return 0;
}
