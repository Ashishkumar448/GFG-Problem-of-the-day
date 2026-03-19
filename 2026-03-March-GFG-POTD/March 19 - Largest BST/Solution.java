// class Node
// {
//     int data;
//     Node left, right;

//     public Node(int d)
//     {
//         data = d;
//         left = right = null;
//     }
// }

class Solution {

    static class Info {
        int min, max, size;
        boolean isBST;

        Info(int min, int max, int size, boolean isBST) {
            this.min = min;
            this.max = max;
            this.size = size;
            this.isBST = isBST;
        }
    }

    static int maxSize = 0;

    static int largestBst(Node root) {
        maxSize = 0;
        solve(root);
        return maxSize;
    }

    static Info solve(Node root) {
        // Base case
        if (root == null) {
            return new Info(Integer.MAX_VALUE, Integer.MIN_VALUE, 0, true);
        }

        Info left = solve(root.left);
        Info right = solve(root.right);

        // Check BST condition
        if (left.isBST && right.isBST && root.data > left.max && root.data < right.min) {
            
            int size = left.size + right.size + 1;
            maxSize = Math.max(maxSize, size);

            int min = Math.min(root.data, left.min);
            int max = Math.max(root.data, right.max);

            return new Info(min, max, size, true);
        }

        // Not a BST
        return new Info(Integer.MIN_VALUE, Integer.MAX_VALUE, 
                        Math.max(left.size, right.size), false);
    }
}
