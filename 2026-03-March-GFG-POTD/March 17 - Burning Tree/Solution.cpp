#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = buildParentMap(root, parentMap, target);

        queue<Node*> q;
        unordered_set<Node*> visited;

        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // left
                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                    burned = true;
                }

                // right
                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                    burned = true;
                }

                // parent
                if (parentMap[curr] && !visited.count(parentMap[curr])) {
                    q.push(parentMap[curr]);
                    visited.insert(parentMap[curr]);
                    burned = true;
                }
            }

            if (burned) time++;
        }

        return time;
    }

private:
    Node* buildParentMap(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
        queue<Node*> q;
        q.push(root);

        Node* targetNode = NULL;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target) {
                targetNode = curr;
            }

            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }
};
