#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* down;

    Node(int data) {
        this->data = data;
        right = nullptr;
        down = nullptr;
    }
};

class Linked_list_2D_Matrix {
public:
    void display(Node* head) {
        Node* Dp = head;
        while (Dp != nullptr) {
            Node* Rp = Dp;
            while (Rp != nullptr) {
                cout << Rp->data << " ";
                if (Rp->right != nullptr)
                    cout << Rp->right->data << " ";
                else
                    cout << "null ";
                if (Rp->down != nullptr)
                    cout << Rp->down->data << " ";
                else
                    cout << "null ";
                Rp = Rp->right;
            }
            Dp = Dp->down;
        }
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& arr) {
        if (arr.empty()) return nullptr;

        int n = arr.size();
        vector<vector<Node*>> nodes(n, vector<Node*>(n));

        // Create all nodes and store them in a 2D vector of nodes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nodes[i][j] = new Node(arr[i][j]);
            }
        }

        // Set right and down pointers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n) {
                    nodes[i][j]->right = nodes[i][j + 1];
                }
                if (i + 1 < n) {
                    nodes[i][j]->down = nodes[i + 1][j];
                }
            }
        }

        return nodes[0][0];
    }
};

int main() {
    int t;
    cin >> t;
    Linked_list_2D_Matrix ll2d;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        Node* head = obj.construct(mat);
        ll2d.display(head);
        cout << endl;
    }

    return 0;
}
