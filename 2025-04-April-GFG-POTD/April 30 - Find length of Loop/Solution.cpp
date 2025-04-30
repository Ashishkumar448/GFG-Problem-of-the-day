#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void makeLoop(Node* head, Node* tail, int x) {
    if (x == 0) return;
    Node* curr = head;
    for (int i = 1; i < x; i++) {
        curr = curr->next;
    }
    tail->next = curr;
}

int countLoopLength(Node* nodeInLoop) {
    Node* current = nodeInLoop;
    int count = 1;
    while (current->next != nodeInLoop) {
        current = current->next;
        count++;
    }
    return count;
}

int countNodesinLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return countLoopLength(slow);
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, val, c;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];
        cin >> c;

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < n; ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        makeLoop(head, tail, c);
        cout << countNodesinLoop(head) << endl;
        cout << "~" << endl;
    }
    return 0;
}
