#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Use a max heap
        priority_queue<int> maxHeap(arr.begin(), arr.end());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
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
        for (int i = 0; i < n; i++) cin >> arr[i];

        int k;
        cin >> k;

        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);

        for (int num : ans) {
            cout << num << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
