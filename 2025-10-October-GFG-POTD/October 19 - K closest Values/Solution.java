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
     // Function to return k closest values to the target in BST
    public ArrayList<Integer> getKClosest(Node root, int target, int k) {
        ArrayList<Integer> inorderList = new ArrayList<>();
        inorderTraversal(root, inorderList);

        // Sort based on absolute difference first, then by value
        Collections.sort(inorderList, (a, b) -> {
            int diffA = Math.abs(a - target);
            int diffB = Math.abs(b - target);
            if (diffA == diffB)
                return a - b; // smaller value first in tie
            return diffA - diffB;
        });

        // Pick first k elements
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < k && i < inorderList.size(); i++) {
            result.add(inorderList.get(i));
        }

        return result;
    }

    // Helper function for inorder traversal
    private void inorderTraversal(Node root, ArrayList<Integer> list) {
        if (root == null) return;
        inorderTraversal(root.left, list);
        list.add(root.data);
        inorderTraversal(root.right, list);
    }
}
