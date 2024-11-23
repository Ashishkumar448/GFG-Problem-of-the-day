#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int getMinDiff(int k, vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;  // Only one tower, no difference

        sort(arr.begin(), arr.end());  // Sort the array

        int minHeight = arr[0];
        int maxHeight = arr[n - 1];
        int result = maxHeight - minHeight;  // Initial difference

        for (int i = 0; i < n - 1; i++) {
            int newMin = min(arr[0] + k, arr[i + 1] - k);
            int newMax = max(arr[i] + k, arr[n - 1] - k);
            
            result = min(result, newMax - newMin);
        }
        
        return result;
    }
};

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        int res = obj.getMinDiff(k, arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
