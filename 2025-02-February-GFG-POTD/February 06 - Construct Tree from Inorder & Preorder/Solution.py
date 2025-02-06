#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = right = NULL;
    }
};

class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> inorderMap;

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        preIndex = 0;
        inorderMap.clear();

        // Store indices of inorder elements for quick lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return constructTree(inorder, preorder, 0, inorder.size() - 1);
    }

private:
    Node* constructTree(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return NULL;
        }

        // Pick the current node from Preorder traversal
        int rootValue = preorder[preIndex++];
        Node* root = new Node(rootValue);

        // Find the root index in inorder traversal
        int inIndex = inorderMap[rootValue];

        // Recursively build the left and right subtrees
        root->left = constructTree(inorder, preorder, inStart, inIndex - 1);
        root->right = constructTree(inorder, preorder, inIndex + 1, inEnd);

        return root;
    }
};

// Function to print postorder traversal of the tree
void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> inorder(n), preorder(n);

        for (int i = 0; i < n; i++) cin >> inorder[i];
        for (int i = 0; i < n; i++) cin >> preorder[i];

        Solution obj;
        Node* root = obj.buildTree(inorder, preorder);
        postOrder(root);
        cout << endl;
    }
    return 0;
}
