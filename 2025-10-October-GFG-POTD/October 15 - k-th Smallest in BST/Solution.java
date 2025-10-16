/*
class Node {
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    int count = 0;   // To count visited nodes
    int result = -1; // To store the k-th smallest value

    public int kthSmallest(Node root, int k) {
        inorder(root, k);
        return result;
    }

    private void inorder(Node root, int k) {
        if (root == null) return;

        // Traverse left subtree
        inorder(root.left, k);

        // Visit current node
        count++;
        if (count == k) {
            result = root.data;
            return;
        }

        // Traverse right subtree
        inorder(root.right, k);
    }
}
