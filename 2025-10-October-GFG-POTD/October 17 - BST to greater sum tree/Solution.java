/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
} */

class Solution {
    static int sum = 0;

    public static void transformTree(Node root) {
        sum = 0; // Reset before starting
        transform(root);
    }

    private static void transform(Node root) {
        if (root == null)
            return;

        // Traverse right subtree first (larger values)
        transform(root.right);

        // Process current node
        int temp = root.data;
        root.data = sum;
        sum += temp;

        // Traverse left subtree (smaller values)
        transform(root.left);
    }
}
