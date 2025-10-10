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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->data);
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            
            if (!leftToRight)
                reverse(level.begin(), level.end());
            
            result.insert(result.end(), level.begin(), level.end());
            leftToRight = !leftToRight; // toggle direction
        }
        
        return result;
    }
};
