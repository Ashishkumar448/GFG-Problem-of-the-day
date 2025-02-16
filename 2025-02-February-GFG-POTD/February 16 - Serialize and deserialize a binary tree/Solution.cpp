#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
public:
    vector<int> serialize(Node* root) {
        vector<int> res;
        serializeHelper(root, res);
        return res;
    }

    Node* deSerialize(vector<int>& data) {
        int index = 0;
        return deSerializeHelper(data, index);
    }

private:
    void serializeHelper(Node* root, vector<int>& res) {
        if (!root) { res.push_back(-1); return; }
        res.push_back(root->data);
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    Node* deSerializeHelper(vector<int>& data, int& index) {
        if (index == data.size() || data[index] == -1) {
            index++;
            return NULL;
        }
        Node* node = new Node(data[index++]);
        node->left = deSerializeHelper(data, index);
        node->right = deSerializeHelper(data, index);
        return node;
    }
};
