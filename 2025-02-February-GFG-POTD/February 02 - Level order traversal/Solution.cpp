#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result; // Return empty if tree is empty
        }

        queue<Node*> q;
        q.push(root); // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front(); // Get the front node
                q.pop(); // Remove it from the queue
                currentLevel.push_back(currentNode->data); // Add current node's value to the level list

                // Add left child to the queue if it exists
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                // Add right child to the queue if it exists
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel); // Add current level list to the result
        }

        return result; // Return the final result containing all levels
    }
};

// Function to build tree from input string
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N') {
        return nullptr;
    }

    stringstream ss(str);
    string token;
    getline(ss, token, ' ');
    Node* root = new Node(stoi(token));
    
    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty() && getline(ss, token, ' ')) {
        Node* currNode = queue.front();
        queue.pop();

        if (token != "N") {
            currNode->left = new Node(stoi(token));
            queue.push(currNode->left);
        }

        if (!getline(ss, token, ' ')) break; // Break if no more tokens

        if (token != "N") {
            currNode->right = new Node(stoi(token));
            queue.push(currNode->right);
        }
    }

    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after integer input

    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        
        Solution solution;
        vector<vector<int>> res = solution.levelOrder(root);
        
        for (const auto& level : res) {
            for (int num : level) {
                cout << num << " ";
            }
        }
        cout << endl << "~" << endl;
    }

    return 0;
}
