/*
class Node {
    int data;
    Node left, right;

    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    // Helper class to store include/exclude results for each node
    static class Pair {
        int include; // sum when including this node
        int exclude; // sum when excluding this node

        Pair(int include, int exclude) {
            this.include = include;
            this.exclude = exclude;
        }
    }

    public int getMaxSum(Node root) {
        Pair result = solve(root);
        return Math.max(result.include, result.exclude);
    }

    private Pair solve(Node node) {
        if (node == null) {
            return new Pair(0, 0);
        }

        Pair left = solve(node.left);
        Pair right = solve(node.right);

        // If we include this node, we cannot include its children
        int include = node.data + left.exclude + right.exclude;

        // If we exclude this node, we can take max(include, exclude) from each child
        int exclude = Math.max(left.include, left.exclude) + Math.max(right.include, right.exclude);

        return new Pair(include, exclude);
    }
}
