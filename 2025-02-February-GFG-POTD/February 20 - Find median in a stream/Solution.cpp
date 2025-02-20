#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int>& arr) {
        vector<double> medians;
        priority_queue<int> maxHeap; // Left half (max heap)
        priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (min heap)

        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Find median
            if (maxHeap.size() == minHeap.size()) {
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                medians.push_back(maxHeap.top());
            }
        }
        return medians;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        vector<int> nums;
        int num;
        while (iss >> num) {
            nums.push_back(num);
        }

        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        for (double i : ans) {
            printf("%.1f ", i);
        }
        cout << endl << "~" << endl;
    }
    return 0;
}
