// { Driver Code Starts
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int arr[], int n, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove elements not part of this window (out of bounds for subarray)
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements from the deque that are smaller than the current element,
            // because they will not be the maximum for any future subarray.
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add the current element index at the back of the deque
            dq.push_back(i);

            // The maximum of the current window is at the front of the deque
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);

        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
