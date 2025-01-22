#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* l1, Node* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->data;
                l2 = l2->next;
            }
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        Node* res = reverse(dummy->next);
        while (res != nullptr && res->data == 0 && res->next != nullptr) {
            res = res->next;
        }
        return res;
    }
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n;
        Node* num1 = nullptr;
        Node* tail1 = nullptr;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (num1 == nullptr) {
                num1 = newNode;
                tail1 = newNode;
            } else {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }

        cin >> m;
        Node* num2 = nullptr;
        Node* tail2 = nullptr;
        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (num2 == nullptr) {
                num2 = newNode;
                tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }

        Solution sol;
        Node* res = sol.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}
