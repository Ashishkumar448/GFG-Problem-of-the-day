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
    // Function to count nodes in BST
    private int countNodes(Node root) {
        if (root == null) return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
    
    // Helper for inorder traversal to find median
    private int findMedianUtil(Node root, int targetIndex, int[] count) {
        if (root == null) return -1;
        
        // Search left subtree
        int left = findMedianUtil(root.left, targetIndex, count);
        if (left != -1) return left; // Found
        
        // Visit current node
        count[0]++;
        if (count[0] == targetIndex) {
            return root.data;
        }
        
        // Search right subtree
        return findMedianUtil(root.right, targetIndex, count);
    }
    
    public int findMedian(Node root) {
        if (root == null) return 0;
        
        // Step 1: count total nodes
        int n = countNodes(root);
        
        // Step 2: find target index
        int targetIndex;
        if (n % 2 == 0) targetIndex = n / 2;      // even
        else targetIndex = (n + 1) / 2;           // odd
        
        // Step 3: second inorder traversal to get target element
        int[] count = new int[1]; // acts as mutable counter
        return findMedianUtil(root, targetIndex, count);
    }
}
