#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class BT_To_DLL {
public:
    Node* buildTree(string str) {
        if (str.length() == 0 || str[0] == 'N') {
            return nullptr;
        }

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
            if (i >= ip.size()) break;
            currVal = ip[i];

            if (currVal != "N") {
                currNode->right = new Node(stoi(currVal));
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void printList(Node* head) {
        Node* prev = head;
        while (head != nullptr) {
            cout << head->data << " ";
            prev = head;
            head = head->right;
        }
        cout << endl;
        while (prev != nullptr) {
            cout << prev->data << " ";
            prev = prev->left;
        }
    }
};

class Solution {
public:
    Node* prev = nullptr;
    Node* head = nullptr;

    Node* bToDLL(Node* root) {
        if (root == nullptr)
            return nullptr;

        bToDLL(root->left);

        if (prev == nullptr) {
            head = root;
        } else {
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        bToDLL(root->right);

        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string s;
        getline(cin, s);
        
        BT_To_DLL tree;
        Node* root = tree.buildTree(s);
        
        Solution obj;
        Node* ans = obj.bToDLL(root);
        tree.printList(ans);
        cout << endl;
    }

    return 0;
}
