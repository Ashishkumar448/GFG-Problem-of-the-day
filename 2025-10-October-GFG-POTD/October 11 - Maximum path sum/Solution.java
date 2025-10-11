/*
class Node{
    int data;
    Node left, right;
    Node(int d){
        data=d;
        left=right=null;
    }
}
*/

class Solution {
    int res; // global variable to store maximum path sum

    int findMaxSum(Node root) {
        res = Integer.MIN_VALUE;
        maxPathDown(root);
        return res;
    }

    int maxPathDown(Node node) {
        if (node == null) return 0;

        // Compute maximum path sum on left and right subtrees
        int left = Math.max(0, maxPathDown(node.left)); 
        int right = Math.max(0, maxPathDown(node.right));

        // Update global result (max path sum through the current node)
        res = Math.max(res, node.data + left + right);

        // Return max path sum going upward (only one branch)
        return node.data + Math.max(left, right);
    }
}
