/*
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    private int moves = 0; // total moves

    public int distCandy(Node root) {
        dfs(root);
        return moves;
    }

    private int dfs(Node node) {
        if (node == null) return 0;

        int leftBalance = dfs(node.left);   // candies to move from left subtree
        int rightBalance = dfs(node.right); // candies to move from right subtree

        // total moves needed to balance children
        moves += Math.abs(leftBalance) + Math.abs(rightBalance);

        // return current node's balance
        // positive → extra candies to give to parent
        // negative → needs candies from parent
        return node.data + leftBalance + rightBalance - 1;
    }
}
