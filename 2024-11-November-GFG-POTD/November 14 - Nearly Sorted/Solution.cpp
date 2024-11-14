#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        // Min-heap (priority queue) to maintain the smallest element at the root
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = arr.size();

        // Insert the first k+1 elements into the min-heap
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.push(arr[i]);
        }

        int index = 0; // Index for the sorted portion of the array
        for (int i = k + 1; i < n; i++) {
            // Extract the minimum element from the heap and place it in the sorted portion
            arr[index++] = minHeap.top();
            minHeap.pop();
            // Add the next element from the array to the heap
            minHeap.push(arr[i]);
        }

        // Extract remaining elements from the heap and place them in the array
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;

        Solution obj;
        obj.nearlySorted(arr, k);

        for (int i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
