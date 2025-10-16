/*
class Node {
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/

class Solution {
    Node removekeys(Node root, int l, int r) {
        // Base case: if tree is empty
        if (root == null) return null;

        // First, fix the left and right subtrees recursively
        root.left = removekeys(root.left, l, r);
        root.right = removekeys(root.right, l, r);

        // If current node's value is smaller than l, 
        // discard left subtree and current node
        if (root.data < l) {
            return root.right;
        }

        // If current node's value is greater than r,
        // discard right subtree and current node
        if (root.data > r) {
            return root.left;
        }

        // Current node is in range
        return root;
    }
}
