/*
class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
}*/

class Solution {
    public boolean isDeadEnd(Node root) {
        return helper(root, 1, Integer.MAX_VALUE);
    }

    private boolean helper(Node node, int min, int max) {
        if (node == null) return false;

        // If no range is left to insert any new node
        if (min == max) return true;

        // Check left and right subtrees
        return helper(node.left, min, node.data - 1) ||
               helper(node.right, node.data + 1, max);
    }
}
