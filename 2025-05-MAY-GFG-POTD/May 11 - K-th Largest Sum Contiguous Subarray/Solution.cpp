#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += arr[j];

            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    return minHeap.top();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        vector<int> arr;

        while (ss >> num) {
            arr.push_back(num);
        }

        int k;
        cin >> k;
        cin.ignore();

        cout << kthLargest(arr, k) << endl;
        cout << "~" << endl;
    }

    return 0;
}
