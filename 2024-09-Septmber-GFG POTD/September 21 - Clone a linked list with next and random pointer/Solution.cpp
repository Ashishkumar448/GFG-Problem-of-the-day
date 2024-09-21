// C++ solution to clone a linked list with next and random pointer

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node
struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int d) {
        data = d;
        next = random = NULL;
    }
};

class Solution {
public:
    // Function to clone a linked list with next and random pointer.
    Node* copyList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Create the copy of each node and insert it between the original nodes.
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            Node* copy = new Node(curr->data);
            curr->next = copy;
            copy->next = next;
            curr = next;
        }

        // Step 2: Update the random pointers for the copied nodes.
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original list and the copied list.
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while (original != NULL) {
            original->next = original->next->next;
            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};

// Utility function to add a node at the end of the list
Node* addToTheLast(Node* head, Node* node) {
    if (head == NULL) {
        return node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = node;
        return head;
    }
}

// Validation function
bool validation(Node* head, Node* res) {
    Node* temp1 = head;
    Node* temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 != len2) return false;

    unordered_map<Node*, Node*> nodeMap;

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        if (temp1 == temp2) return false;
        if (temp1->data != temp2->data) return false;

        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL)) {
            return false;
        }
        if (temp1->random != NULL && temp2->random != NULL &&
            temp1->random->data != temp2->random->data) {
            return false;
        }
        nodeMap[temp1] = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        if (temp1->random != NULL && nodeMap[temp1->random] != temp2->random) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

// Main function
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline after the integer input

    while (t--) {
        Node *head = NULL, *head2 = NULL;
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) nums.push_back(num);

        int n = nums.size();
        head = addToTheLast(head, new Node(nums[0]));
        head2 = addToTheLast(head2, new Node(nums[0]));

        for (int i = 1; i < n; i++) {
            head = addToTheLast(head, new Node(nums[i]));
            head2 = addToTheLast(head2, new Node(nums[i]));
        }

        string line2;
        getline(cin, line2);
        stringstream ss2(line2);
        vector<int> nums2;
        while (ss2 >> num) nums2.push_back(num);
        int q = nums2.size() / 2;

        for (int i = 0; i < q; i++) {
            int a = nums2[2 * i];
            int b = nums2[2 * i + 1];

            Node* tempA = head;
            Node* temp2A = head2;
            for (int j = 0; j < a - 1 && tempA != NULL; j++) {
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node* tempB = head;
            Node* temp2B = head2;
            for (int j = 0; j < b - 1 && tempB != NULL; j++) {
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            if (a <= n) {
                tempA->random = tempB;
                temp2A->random = temp2B;
            }
        }

        Solution g;
        Node* res = g.copyList(head);

        if (validation(head, res) && validation(head2, res))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

