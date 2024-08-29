#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    int countLoopLength(Node* node) {
        Node* temp = node;
        int length = 1;
        
        while (temp->next != node) {
            length++;
            temp = temp->next;
        }
        
        return length;
    }

    int countNodesinLoop(Node* head) {
        Node *slow = head, *fast = head;
        
        // Step 1: Detect the loop using the Tortoise and Hare method
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If slow and fast meet, there's a loop
            if (slow == fast) {
                // Step 2: Find the loop length
                return countLoopLength(slow);
            }
        }
        
        // No loop found
        return 0;
    }
};

// Driver Code
void makeLoop(Node* head, Node* tail, int x) {
    if (x == 0) return;

    Node* curr = head;
    for (int i = 1; i < x; i++)
        curr = curr->next;

    tail->next = curr;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            arr.push_back(val);
        }
        cin >> k;

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        makeLoop(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}
