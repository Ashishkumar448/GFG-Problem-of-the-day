#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int key) : data(key), next(nullptr) {}
};

class SortLL {
public:
    static Node* head;

    static void addToTheLast(Node* node) {
        if (head == nullptr) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = node;
        }
    }

    static void printList(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    static void clearList(Node* head) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

Node* SortLL::head = nullptr;

class GfG {
public:
    static Node* quickSort(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        Node* left;
        Node* pivot;
        Node* right;
        tie(left, pivot, right) = partition(node);

        left = quickSort(left);
        right = quickSort(right);

        return concatenate(left, pivot, right);
    }

private:
    static tuple<Node*, Node*, Node*> partition(Node* node) {
        Node* pivot = node;
        Node leftDummy(0), rightDummy(0);
        Node* left = &leftDummy;
        Node* right = &rightDummy;
        Node* current = node->next;

        while (current != nullptr) {
            if (current->data < pivot->data) {
                left->next = current;
                left = left->next;
            } else {
                right->next = current;
                right = right->next;
            }
            current = current->next;
        }

        left->next = nullptr;
        right->next = nullptr;

        return {leftDummy.next, pivot, rightDummy.next};
    }

    static Node* concatenate(Node* left, Node* pivot, Node* right) {
        Node* head = pivot;

        if (left != nullptr) {
            head = left;
            Node* temp = left;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = pivot;
        }

        pivot->next = right;
        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int data;
        SortLL::head = nullptr;

        if (iss >> data) {
            SortLL::head = new Node(data);
            SortLL::addToTheLast(SortLL::head);

            while (iss >> data) {
                SortLL::addToTheLast(new Node(data));
            }
        }

        GfG gfg;
        Node* sortedHead = gfg.quickSort(SortLL::head);
        SortLL::printList(sortedHead);
        SortLL::clearList(sortedHead);
        cout << "~" << endl;
    }

    return 0;
}
