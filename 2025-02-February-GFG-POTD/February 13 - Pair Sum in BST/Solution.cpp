#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void inOrderTraversal(Node* root, vector<int>& nodes) {
    if (!root) return;
    inOrderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inOrderTraversal(root->right, nodes);
}

bool findTarget(Node* root, int target) {
    vector<int> nodes;
    inOrderTraversal(root, nodes);
    int left = 0, right = nodes.size() - 1;
    while (left < right) {
        int sum = nodes[left] + nodes[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
