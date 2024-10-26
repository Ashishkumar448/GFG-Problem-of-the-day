#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int a) {
        data = a;
        next = nullptr;
    }
};

class Solution {
public:
    static int count(Node* head, int key) {
        int count = 0;
        Node* current = head;
        
        // Traverse the linked list
        while (current != nullptr) {
            // Check if the current node's data is equal to the key
            if (current->data == key) {
                count++;
            }
            current = current->next;
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        vector<int> arr;
        int n;
        cin >> n; // number of elements in the list

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            arr.push_back(val);
        }

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        int key;
        cin >> key;
        Solution ob;
        cout << ob.count(head, key) << endl;

        cout << "~" << endl;

        // Free the memory
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    return 0;
}
