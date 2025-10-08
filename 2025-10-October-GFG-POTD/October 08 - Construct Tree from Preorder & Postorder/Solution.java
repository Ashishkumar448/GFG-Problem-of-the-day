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
     int preIndex = 0;
    Map<Integer, Integer> postMap = new HashMap<>();

    public Node constructTree(int[] pre, int[] post) {
        // Map to store value -> index in postorder for O(1) lookups
        for (int i = 0; i < post.length; i++) {
            postMap.put(post[i], i);
        }
        return build(pre, post, 0, post.length - 1);
    }

    private Node build(int[] pre, int[] post, int l, int r) {
        if (preIndex >= pre.length || l > r) return null;

        // Create root from preorder
        Node root = new Node(pre[preIndex++]);

        // If only one node, return it
        if (l == r || preIndex >= pre.length) return root;

        // Find index of next preorder element in postorder
        int postIndex = postMap.get(pre[preIndex]);

        // Build left and right subtrees
        root.left = build(pre, post, l, postIndex);
        root.right = build(pre, post, postIndex + 1, r - 1);

        return root;
    }
}
