// C++ solution for K Closest Points to Origin
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, vector<int>>> maxHeap;
    for (auto &p : points) {
        int dist = p[0]*p[0] + p[1]*p[1];
        maxHeap.push({dist, p});
        if (maxHeap.size() > k) maxHeap.pop();
    }
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return result;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int k, n; cin >> k >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];
        vector<vector<int>> ans = kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (auto &p : ans) cout << p[0] << " " << p[1] << "\n";
        cout << "~\n";
    }
    return 0;
}
