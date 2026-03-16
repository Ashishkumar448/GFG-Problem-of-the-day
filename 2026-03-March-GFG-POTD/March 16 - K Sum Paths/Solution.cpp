#include <unordered_map>
using namespace std;

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int countAllPaths(Node* root, int k) {
        unordered_map<long long, int> mp;
        mp[0] = 1; // base case
        return dfs(root, 0, k, mp);
    }

private:
    int dfs(Node* node, long long currSum, int k, unordered_map<long long, int>& mp) {
        if (!node) return 0;

        currSum += node->data;

        int count = mp[currSum - k];

        mp[currSum]++;

        count += dfs(node->left, currSum, k, mp);
        count += dfs(node->right, currSum, k, mp);

        mp[currSum]--; // backtrack

        return count;
    }
};
