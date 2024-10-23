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
    // Return the sum of last k nodes
    int sumOfLastN_Nodes(Node* head, int n) {
        // Step 1: Calculate the length of the linked list
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // If n is greater than the length of the list, reset n to length
        if (n > length) {
            n = length;
        }

        // Step 2: Calculate the starting position
        int startPos = length - n;

        // Step 3: Traverse to the starting node and calculate the sum
        current = head;
        int sum = 0, index = 0;

        // Traverse the linked list again and sum up the last 'n' nodes
        while (current != nullptr) {
            if (index >= startPos) {
                sum += current->data;
            }
            index++;
            current = current->next;
        }

        return sum;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int num;
        while (cin >> num) {
            arr.push_back(num);
            if (cin.peek() == '\n') break;
        }
        int n;
        cin >> n;

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }

    return 0;
}
