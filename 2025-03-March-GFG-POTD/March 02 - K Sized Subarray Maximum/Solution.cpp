#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxOfSubarrays(int arr[], int n, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);

        // Remove elements from the front of the deque that are out of the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Add the maximum element of the current window to the result if the window is full
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        vector<int> res = maxOfSubarrays(arr, n, k);

        // printing the elements of the vector
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}
