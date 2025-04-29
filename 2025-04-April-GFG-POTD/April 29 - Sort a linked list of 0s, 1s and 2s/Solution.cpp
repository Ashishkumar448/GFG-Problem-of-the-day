#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* segregate(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        int count[3] = {0, 0, 0}; // count[0] for 0s, count[1] for 1s, count[2] for 2s
        Node* temp = head;
        
        while (temp != nullptr) {
            count[temp->data]++;
            temp = temp->next;
        }
        
        temp = head;
        int i = 0;
        
        while (temp != nullptr) {
            if (count[i] == 0) {
                i++;
            } else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        
        return head;
    }
};

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        vector<int> arr;
        while (ss >> num) {
            arr.push_back(num);
        }

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); i++) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        head = ob.segregate(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
