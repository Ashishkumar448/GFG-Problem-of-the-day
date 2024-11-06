#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int treePathsSum(Node* root) {
        if (root == nullptr) return 0;

        int totalSum = 0;
        stack<pair<Node*, int>> stack;
        stack.push({root, root->data});

        while (!stack.empty()) {
            auto current = stack.top();
            stack.pop();
            Node* node = current.first;
            int currentSum = current.second;

            if (node->left == nullptr && node->right == nullptr) {
                totalSum += currentSum;
            }

            if (node->right != nullptr) {
                stack.push({node->right, currentSum * 10 + node->right->data});
            }
            if (node->left != nullptr) {
                stack.push({node->left, currentSum * 10 + node->left->data});
            }
        }

        return totalSum;
    }
};

Node* buildTree(const string& str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    istringstream iss(str);
    string val;
    iss >> val;
    Node* root = new Node(stoi(val));
    queue<Node*> queue;
    queue.push(root);

    while (iss >> val) {
        Node* currNode = queue.front();
        queue.pop();

        if (val != "N") {
            currNode->left = new Node(stoi(val));
            queue.push(currNode->left);
        }

        if (!(iss >> val)) break;
        if (val != "N") {
            currNode->right = new Node(stoi(val));
            queue.push(currNode->right);
        }
    }

    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.treePathsSum(root) << endl;
    }
    return 0;
}
