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

class Solution {
public:
    struct Result {
        int maxLen = 0;
        int maxSum = 0;
    };

    int sumOfLongRootToLeafPath(Node* root) {
        Result res;
        dfs(root, 0, 0, res);
        return res.maxSum;
    }

private:
    void dfs(Node* node, int currLen, int currSum, Result &res) {
        if (!node) return;

        currSum += node->data;
        currLen += 1;

        if (!node->left && !node->right) {
            if (currLen > res.maxLen) {
                res.maxLen = currLen;
                res.maxSum = currSum;
            } else if (currLen == res.maxLen) {
                res.maxSum = max(res.maxSum, currSum);
            }
        }

        dfs(node->left, currLen, currSum, res);
        dfs(node->right, currLen, currSum, res);
    }
};
