#include <bits/stdc++.h>
using namespace std;

struct Node {
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
    int sumK(Node* root, int k) {
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1; // Base case: sum 0 exists once
        return findPaths(root, 0, k, prefixSumMap);
    }

private:
    int findPaths(Node* node, int currSum, int k, unordered_map<int, int>& prefixSumMap) {
        if (!node) return 0;

        // Update current prefix sum
        currSum += node->data;

        // Count the number of times (currSum - k) has occurred
        int count = prefixSumMap[currSum - k];

        // Store the current sum in the map
        prefixSumMap[currSum]++;

        // Recur for left and right children
        count += findPaths(node->left, currSum, k, prefixSumMap);
        count += findPaths(node->right, currSum, k, prefixSumMap);

        // Backtrack: Remove the current sum before returning to the parent node
        prefixSumMap[currSum]--;

        return count;
    }
};
