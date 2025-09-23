#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseQueue(queue<int>& q) {
        // base case
        if (q.empty()) return;

        // step 1: remove the front element
        int front = q.front();
        q.pop();

        // step 2: reverse the remaining queue
        reverseQueue(q);

        // step 3: add the removed element at the rear
        q.push(front);
    }
};

// Example usage
int main() {
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    Solution s;
    s.reverseQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
