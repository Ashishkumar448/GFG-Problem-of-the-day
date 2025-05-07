#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string val; iss >> val;) ip.push_back(val);

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

void dfs(Node* node, vector<int>& currentPath, vector<vector<int>>& result) {
    if (!node) return;

    currentPath.push_back(node->data);

    if (!node->left && !node->right) {
        result.push_back(currentPath);
    } else {
        dfs(node->left, currentPath, result);
        dfs(node->right, currentPath, result);
    }

    currentPath.pop_back();
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> result;
    vector<int> currentPath;
    dfs(root, currentPath, result);
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
        vector<vector<int>> res = Paths(root);

        for (auto& path : res) {
            for (int val : path) cout << val << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
