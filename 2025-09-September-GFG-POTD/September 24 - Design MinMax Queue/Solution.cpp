#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
private:
    queue<int> q;
    deque<int> minDeque;
    deque<int> maxDeque;

public:
    SpecialQueue() {}

    void enqueue(int x) {
        q.push(x);

        // Maintain minDeque in increasing order
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);

        // Maintain maxDeque in decreasing order
        while (!maxDeque.empty() && maxDeque.back() < x) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }

    void dequeue() {
        if (!q.empty()) {
            int val = q.front();
            q.pop();

            if (!minDeque.empty() && minDeque.front() == val) {
                minDeque.pop_front();
            }
            if (!maxDeque.empty() && maxDeque.front() == val) {
                maxDeque.pop_front();
            }
        }
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minDeque.front();
    }

    int getMax() {
        return maxDeque.front();
    }
};
