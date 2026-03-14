/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if(root == NULL) return result;

        map<int,int> mp; // hd -> node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            if(mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if(node->left)
                q.push({node->left, hd - 1});

            if(node->right)
                q.push({node->right, hd + 1});
        }

        for(auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
