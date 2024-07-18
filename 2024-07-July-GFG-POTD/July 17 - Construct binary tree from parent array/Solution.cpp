#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = right = nullptr;
    }
};

class CreateTree {
public:
    static void printLevelOrder(Node* root) {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++) {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                int levelSize = q.size();
                vector<int> levelValues;
                for (int j = 0; j < levelSize; j++) {
                    Node* current = q.front();
                    q.pop();
                    levelValues.push_back(current->data);
                    if (current->left) {
                        q.push(current->left);
                    }
                    if (current->right) {
                        q.push(current->right);
                    }
                }
                sort(levelValues.begin(), levelValues.end());
                for (int value : levelValues) {
                    cout << value << " ";
                }
            }
            cout << endl;
        }
    }

    static int height(Node* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int lheight = height(root->left);
            int rheight = height(root->right);

            if (lheight > rheight) {
                return (lheight + 1);
            } else {
                return (rheight + 1);
            }
        }
    }

    static Node* createTree(int parent[], int n) {
        Node* nodes[n];

        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }

        Node* root = nullptr;

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = nodes[i];
            } else {
                Node* parentNode = nodes[parent[i]];
                if (parentNode->left == nullptr) {
                    parentNode->left = nodes[i];
                } else {
                    parentNode->right = nodes[i];
                }
            }
        }

        return root;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int parent[n];

        for (int i = 0; i < n; i++) {
            cin >> parent[i];
        }

        Node* root = CreateTree::createTree(parent, n);
        CreateTree::printLevelOrder(root);
        cout << endl;
    }

    return 0;
}