#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s; )
        ip.push_back(s);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;

        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* findTargetNode(Node* root, int target, unordered_map<Node*, Node*>& parentMap) {
    queue<Node*> queue;
    queue.push(root);
    Node* targetNode = nullptr;

    while (!queue.empty()) {
        Node* curr = queue.front();
        queue.pop();

        if (curr->data == target) {
            targetNode = curr;
        }

        if (curr->left) {
            parentMap[curr->left] = curr;
            queue.push(curr->left);
        }
        if (curr->right) {
            parentMap[curr->right] = curr;
            queue.push(curr->right);
        }
    }

    return targetNode;
}

int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> parentMap;
    Node* targetNode = findTargetNode(root, target, parentMap);

    queue<Node*> queue;
    unordered_set<Node*> visited;
    queue.push(targetNode);
    visited.insert(targetNode);

    int time = 0;

    while (!queue.empty()) {
        int size = queue.size();
        bool flag = false;

        for (int i = 0; i < size; i++) {
            Node* curr = queue.front();
            queue.pop();

            if (curr->left && visited.find(curr->left) == visited.end()) {
                visited.insert(curr->left);
                queue.push(curr->left);
                flag = true;
            }

            if (curr->right && visited.find(curr->right) == visited.end()) {
                visited.insert(curr->right);
                queue.push(curr->right);
                flag = true;
            }

            if (parentMap.find(curr) != parentMap.end() && visited.find(parentMap[curr]) == visited.end()) {
                visited.insert(parentMap[curr]);
                queue.push(parentMap[curr]);
                flag = true;
            }
        }

        if (flag)
            time++;
    }

    return time;
}

// Helper functions for testing

void printInorder(Node* root) {
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

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
        cout << minTime(root, target) << endl;
    }

    return 0;
}
