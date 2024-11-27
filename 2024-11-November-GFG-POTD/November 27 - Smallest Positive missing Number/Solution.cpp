#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the smallest positive number missing from the array
    int missingNumber(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Rearrange the array using cyclic sort
        for (int i = 0; i < n; i++) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                // Swap arr[i] with the element at arr[arr[i] - 1]
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Step 2: Find the first index whose value is incorrect
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are correctly placed, return n + 1
        return n + 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        int res = ob.missingNumber(arr);
        cout << res << endl;
    }
    return 0;
}
