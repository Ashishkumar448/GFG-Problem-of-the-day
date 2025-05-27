#include <vector>
#include <climits>

class Solution {
public:
    int index = 0;

    void findLeaves(const std::vector<int>& preorder, std::vector<int>& result, int min, int max) {
        if (index >= preorder.size()) return;

        int val = preorder[index];
        if (val < min || val > max) return;

        index++;

        int currIndex = index;

        // Left subtree
        findLeaves(preorder, result, min, val - 1);

        // Right subtree
        findLeaves(preorder, result, val + 1, max);

        // If both left and right didn't consume new nodes, it's a leaf
        if (index == currIndex) {
            result.push_back(val);
        }
    }

    std::vector<int> leafNodes(const std::vector<int>& preorder) {
        std::vector<int> result;
        index = 0;
        findLeaves(preorder, result, INT_MIN, INT_MAX);
        return result;
    }
};
