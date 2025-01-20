#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "~" << endl;
}

Node* insertSorted(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0);
        Node* tail = &dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1 != nullptr) {
            tail->next = head1;
        } else if (head2 != nullptr) {
            tail->next = head2;
        }

        return dummy.next;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To consume the newline character

    while (T-- > 0) {
        Node* head1 = nullptr;
        Node* head2 = nullptr;

        string input1, input2;
        getline(cin, input1);
        getline(cin, input2);

        stringstream ss1(input1), ss2(input2);
        int value;

        while (ss1 >> value) {
            head1 = insertSorted(head1, value);
        }

        while (ss2 >> value) {
            head2 = insertSorted(head2, value);
        }

        Solution obj;
        Node* mergedHead = obj.sortedMerge(head1, head2);
        printList(mergedHead);
    }

    return 0;
}
