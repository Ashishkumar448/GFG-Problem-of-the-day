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

class Solution {
public:
    pair<int, int> f(Node* root) {
        if (!root) return {0, 0};
        
        auto left = f(root->left);
        auto right = f(root->right);
        
        int height = 1 + max(left.first, right.first);
        int diameter = max({left.second, right.second, left.first + right.first});
        
        return {height, diameter};
    }

    int diameter(Node* root) {
        return f(root).second;
    }
};

// Function to build tree from input string
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N') return nullptr;
    
    vector<string> ip;
    stringstream ss(str);
    string word;
    while (ss >> word) ip.push_back(word);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        string leftVal = ip[i++];
        if (leftVal != "N") {
            currNode->left = new Node(stoi(leftVal));
            q.push(currNode->left);
        }

        if (i >= ip.size()) break;
        string rightVal = ip[i++];
        if (rightVal != "N") {
            currNode->right = new Node(stoi(rightVal));
            q.push(currNode->right);
        }
    }

    return root;
}

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution sol;
        cout << sol.diameter(root) << endl;
    }

    return 0;
}
