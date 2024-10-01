#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node class representing a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to return a list of integers denoting the node values of both the BSTs in sorted order.
    vector<int> merge(Node* root1, Node* root2) {
        vector<int> list1, list2;
        
        // Perform inorder traversal to get sorted elements from both BSTs
        inorder(root1, list1);
        inorder(root2, list2);
        
        // Merge the two sorted lists
        return mergeSortedLists(list1, list2);
    }

private:
    // Helper function for inorder traversal
    void inorder(Node* root, vector<int>& list) {
        if (root == NULL) return;
        inorder(root->left, list);
        list.push_back(root->data);
        inorder(root->right, list);
    }
    
    // Helper function to merge two sorted lists
    vector<int> mergeSortedLists(vector<int>& list1, vector<int>& list2) {
        vector<int> mergedList;
        int i = 0, j = 0;

        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) {
                mergedList.push_back(list1[i]);
                i++;
            } else {
                mergedList.push_back(list2[j]);
                j++;
            }
        }

        // Add any remaining elements
        while (i < list1.size()) {
            mergedList.push_back(list1[i]);
            i++;
        }

        while (j < list2.size()) {
            mergedList.push_back(list2[j]);
            j++;
        }

        return mergedList;
    }
};

// Helper function to build tree from string input
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    stringstream ss(str);
    string word;
    while (ss >> word) ip.push_back(word);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Driver code to test the solution
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        Solution sol;
        vector<int> result = sol.merge(root1, root2);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
