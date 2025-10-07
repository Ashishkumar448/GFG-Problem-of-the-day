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
    vector<int> bottomView(Node* root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> mp; // horizontal distance -> node value
        queue<pair<Node*, int>> q; // (node, hd)
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // Update map (latest node at hd)
            mp[hd] = node->data;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto& it : mp)
            result.push_back(it.second);

        return result;
    }
};
