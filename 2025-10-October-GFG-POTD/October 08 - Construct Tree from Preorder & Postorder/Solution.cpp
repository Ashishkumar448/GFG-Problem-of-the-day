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
    int preIndex = 0;
    unordered_map<int, int> postMap;

public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        for (int i = 0; i < post.size(); i++) {
            postMap[post[i]] = i;
        }
        return build(pre, post, 0, post.size() - 1);
    }

private:
    Node* build(vector<int>& pre, vector<int>& post, int l, int r) {
        if (preIndex >= pre.size() || l > r)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (l == r || preIndex >= pre.size())
            return root;

        int postIndex = postMap[pre[preIndex]];

        root->left = build(pre, post, l, postIndex);
        root->right = build(pre, post, postIndex + 1, r - 1);

        return root;
    }
};
