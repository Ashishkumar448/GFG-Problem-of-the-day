/*
class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
} */
class Solution {
    public int findMaxFork(Node root, int k) {
        int result = -1; // -1 if no such element exists
        while (root != null) {
            if (root.data <= k) {
                result = root.data; // potential answer
                root = root.right; // look for a bigger valid value
            } else {
                root = root.left; // too big, look left
            }
        }
        return result;
    }
}
