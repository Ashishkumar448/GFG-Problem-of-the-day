#include <iostream>
#include <vector>
#include <sstream>
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
    // Function to count nodes of a linked list.
    int getCount(Node* head) {
        int count = 0;
        Node* current = head;
        // Traverse the linked list until the end
        while (current != nullptr) {
            count++;
            current = current->next; // Move to the next node
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        
        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getCount(head) << endl;
    }

    return 0;
}
