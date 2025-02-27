#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    stack<int> stack;
    stack<int> minStack;

public:
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        stack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!stack.empty()) {
            if (stack.top() == minStack.top()) {
                minStack.pop();
            }
            stack.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return stack.empty() ? -1 : stack.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

// Driver Code
int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int q;
        cin >> q; // Number of queries
        Solution g;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                int att;
                cin >> att;
                g.push(att);
            } else if (qt == 2) {
                g.pop();
            } else if (qt == 3) {
                cout << g.peek() << " ";
            } else if (qt == 4) {
                cout << g.getMin() << " ";
            }
        }
        cout << "\n~\n";
    }

    return 0;
}
