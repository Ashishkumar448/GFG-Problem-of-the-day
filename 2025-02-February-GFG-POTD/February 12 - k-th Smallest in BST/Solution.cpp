#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(Node* root, int k) {
        stack<Node*> stack;
        Node* current = root;
        int count = 0;
        
        while (current != NULL || !stack.empty()) {
            // Traverse left subtree
            while (current != NULL) {
                stack.push(current);
                current = current->left;
            }

            // Process the node
            current = stack.top();
            stack.pop();
            count++;

            // If count == k, return the node's data
            if (count == k) return current->data;

            // Move to right subtree
            current = current->right;
        }
        
        return -1; // If k is out of bounds
    }
};

// Utility function to build BST from level order input
Node* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "N") return NULL;

    Node* root = new Node(stoi(arr[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* current = q.front();
        q.pop();

        if (arr[i] != "N") {
            current->left = new Node(stoi(arr[i]));
            q.push(current->left);
        }
        i++;

        if (i >= arr.size()) break;
        if (arr[i] != "N") {
            current->right = new Node(stoi(arr[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin.ignore();
        getline(cin, s);
        vector<string> arr;
        stringstream ss(s);
        string temp;
        while (ss >> temp) arr.push_back(temp);

        Node* root = buildTree(arr);
        int k;
        cin >> k;
        Solution obj;
        cout << obj.kthSmallest(root, k) << endl;
    }
    return 0;
}
