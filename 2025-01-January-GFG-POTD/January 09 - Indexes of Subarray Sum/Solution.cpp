#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        vector<int> result;
        int n = arr.size();
        int currentSum = 0, start = 0;

        for (int end = 0; end < n; end++) {
            // Add current element to the current sum
            currentSum += arr[end];

            // Shrink the window while the current sum is greater than the target
            while (currentSum > target && start <= end) {
                currentSum -= arr[start];
                start++;
            }

            // Check if the current sum equals the target
            if (currentSum == target) {
                result.push_back(start + 1); // 1-based index
                result.push_back(end + 1);   // 1-based index
                return result;
            }
        }

        // If no subarray is found, return [-1]
        result.push_back(-1);
        return result;
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

        int target;
        cin >> target;

        Solution ob;
        vector<int> result = ob.subarraySum(arr, target);

        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
