/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> inorderList;
        inorderTraversal(root, inorderList);

        // Sort based on absolute difference first, then by value
        sort(inorderList.begin(), inorderList.end(), [&](int a, int b) {
            int diffA = abs(a - target);
            int diffB = abs(b - target);
            if (diffA == diffB)
                return a < b; // smaller value first
            return diffA < diffB;
        });

        // Pick first k elements
        vector<int> result;
        for (int i = 0; i < k && i < inorderList.size(); i++) {
            result.push_back(inorderList[i]);
        }

        return result;
    }

private:
    void inorderTraversal(Node* root, vector<int>& list) {
        if (!root) return;
        inorderTraversal(root->left, list);
        list.push_back(root->data);
        inorderTraversal(root->right, list);
    }
};
