#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper to build the tree from string input
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s; )
        ip.push_back(s);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* curr = q.front();
        q.pop();

        if (ip[i] != "N") {
            curr->left = new Node(stoi(ip[i]));
            q.push(curr->left);
        }
        i++;

        if (i >= ip.size()) break;

        if (ip[i] != "N") {
            curr->right = new Node(stoi(ip[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

class Solution {
    unordered_map<Node*, Node*> parentMap;

    void markParents(Node* root, Node* parent) {
        if (!root) return;
        if (parent) parentMap[root] = parent;
        markParents(root->left, root);
        markParents(root->right, root);
    }

    Node* findTarget(Node* root, int target) {
        if (!root) return nullptr;
        if (root->data == target) return root;

        Node* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

public:
    int minTime(Node* root, int target) {
        parentMap.clear();
        markParents(root, nullptr);
        Node* targetNode = findTarget(root, target);

        queue<Node*> q;
        unordered_set<Node*> visited;
        q.push(targetNode);
        visited.insert(targetNode);

        int time = -1;

        while (!q.empty()) {
            int size = q.size();
            bool burntNext = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front(); q.pop();

                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                    burntNext = true;
                }

                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                    burntNext = true;
                }

                if (parentMap.count(curr) && !visited.count(parentMap[curr])) {
                    q.push(parentMap[curr]);
                    visited.insert(parentMap[curr]);
                    burntNext = true;
                }
            }

            if (burntNext) time++;
        }

        return time + 1;
    }
};

// For testing
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        int target;
        cin >> target;
        cin.ignore();

        Node* root = buildTree(s);
        Solution sol;
        cout << sol.minTime(root, target) << endl;
    }
    return 0;
}
