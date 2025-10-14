/*
class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    public int nodeSum(Node root, int l, int r) {
        // Base case
        if (root == null) return 0;
        
        // If root's value is smaller than l, skip left subtree
        if (root.data < l)
            return nodeSum(root.right, l, r);
        
        // If root's value is greater than r, skip right subtree
        if (root.data > r)
            return nodeSum(root.left, l, r);
        
        // Root's value is within [l, r]
        return root.data + nodeSum(root.left, l, r) + nodeSum(root.right, l, r);
    }
}
