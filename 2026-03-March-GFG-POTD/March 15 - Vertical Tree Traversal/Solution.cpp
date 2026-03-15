/*
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        map<int, vector<int>> mp;  // hd -> nodes
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            
            Node* node = current.first;
            int hd = current.second;
            
            mp[hd].push_back(node->data);
            
            if(node->left)
                q.push({node->left, hd - 1});
            
            if(node->right)
                q.push({node->right, hd + 1});
        }
        
        for(auto &it : mp){
            result.push_back(it.second);
        }
        
        return result;
    }
};
