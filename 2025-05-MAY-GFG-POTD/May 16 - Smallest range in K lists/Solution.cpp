#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int data, row, col;
    Node(int d, int r, int c) : data(d), row(r), col(c) {}
};

struct compare {
    bool operator()(Node const& a, Node const& b) {
        return a.data > b.data; // Min-heap based on data
    }
};

vector<int> findSmallestRange(vector<vector<int>>& arr, int k, int n) {
    priority_queue<Node, vector<Node>, compare> pq;
    int maxVal = INT_MIN;

    // Initialize heap with first element of each list
    for (int i = 0; i < k; i++) {
        pq.push(Node(arr[i][0], i, 0));
        maxVal = max(maxVal, arr[i][0]);
    }

    int start = 0, end = INT_MAX;

    while (true) {
        Node curr = pq.top();
        pq.pop();
        int minVal = curr.data;

        if (maxVal - minVal < end - start) {
            start = minVal;
            end = maxVal;
        }

        if (curr.col + 1 < n) {
            int nextVal = arr[curr.row][curr.col + 1];
            pq.push(Node(nextVal, curr.row, curr.col + 1));
            maxVal = max(maxVal, nextVal);
        } else {
            break;
        }
    }

    return {start, end};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        vector<int> range = findSmallestRange(arr, k, n);
        cout << range[0] << " " << range[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
