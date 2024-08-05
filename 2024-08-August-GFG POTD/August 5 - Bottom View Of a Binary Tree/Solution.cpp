#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

// Tree Node
struct Node {
    int data; // data of the node
    int hd; // horizontal distance of the node
    Node* left, * right; // left and right references

    // Constructor of tree node
    Node(int key) {
        data = key;
        hd = INT_MAX;
        left = right = nullptr;
    }
};

// Function to build the tree from the given input string
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    // Create a vector of strings from the input string
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;

        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function to return a vector containing the bottom view of the given tree
vector<int> bottomView(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    // Map to store the mapping of horizontal distance to the node's value
    map<int, int> map;
    // Queue to store nodes for level order traversal
    queue<Node*> queue;

    // Set horizontal distance of root as 0
    root->hd = 0;
    queue.push(root);

    // Perform level order traversal
    while (!queue.empty()) {
        Node* temp = queue.front();
        queue.pop();

        // Get the horizontal distance of the current node
        int hd = temp->hd;

        // Update the map with the node's value at this horizontal distance
        map[hd] = temp->data;

        // If there is a left child, set its horizontal distance and add it to the queue
        if (temp->left != nullptr) {
            temp->left->hd = hd - 1;
            queue.push(temp->left);
        }

        // If there is a right child, set its horizontal distance and add it to the queue
        if (temp->right != nullptr) {
            temp->right->hd = hd + 1;
            queue.push(temp->right);
        }
    }

    // Add the values from the map to the result vector
    for (auto it : map) {
        result.push_back(it.second);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> res = bottomView(root);
        for (int num : res) cout << num << " ";
        cout << endl;
    }
    return 0;
}
