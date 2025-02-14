#include <bits/stdc++.h>
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

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    vector<string> ip;
    stringstream ss(str);
    string temp;
    while (ss >> temp) ip.push_back(temp);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;

        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

bool isBST(Node* root, int lower, int upper) {
    if (!root) return true;
    if (root->data <= lower || root->data >= upper) return false;
    return isBST(root->left, lower, root->data) && isBST(root->right, root->data, upper);
}

bool compareTrees(Node* a, Node* b, vector<pair<int, int>>& mismatch) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->data != b->data) mismatch.push_back({a->data, b->data});
    return compareTrees(a->left, b->left, mismatch) && compareTrees(a->right, b->right, mismatch);
}

class Solution {
public:
    Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

    void correctBST(Node* root) {
        inorder(root);
        if (first && last) swap(first->data, last->data);
        else if (first && middle) swap(first->data, middle->data);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << 0 << endl;
            continue;
        }

        vector<pair<int, int>> mismatch;
        if (!compareTrees(root, duplicate, mismatch)) {
            cout << 0 << endl;
            continue;
        }

        if (mismatch.size() != 2 ||
            mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
