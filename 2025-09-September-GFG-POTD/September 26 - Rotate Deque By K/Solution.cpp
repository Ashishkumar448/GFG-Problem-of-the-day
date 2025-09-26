#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;
        k = k % n;

        if (type == 1) { // Right rotation
            for (int i = 0; i < k; i++) {
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
        } else if (type == 2) { // Left rotation
            for (int i = 0; i < k; i++) {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
    }
};

int main() {
    deque<int> dq1 = {1, 2, 3, 4, 5, 6};
    Solution::rotateDeque(dq1, 1, 2);
    for (int x : dq1) cout << x << " ";  // Output: 5 6 1 2 3 4
    cout << endl;

    deque<int> dq2 = {10, 20, 30, 40, 50};
    Solution::rotateDeque(dq2, 2, 3);
    for (int x : dq2) cout << x << " ";  // Output: 40 50 10 20 30
    cout << endl;

    return 0;
}
