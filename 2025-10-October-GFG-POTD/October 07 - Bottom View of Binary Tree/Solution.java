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
    static class Pair {
        Node node;
        int hd; // horizontal distance

        Pair(Node node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }

    public ArrayList<Integer> bottomView(Node root) {
        ArrayList<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // TreeMap keeps keys sorted by default
        TreeMap<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> queue = new LinkedList<>();

        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            Node node = current.node;
            int hd = current.hd;

            // Update the map (this ensures bottom-most node is recorded)
            map.put(hd, node.data);

            if (node.left != null) queue.add(new Pair(node.left, hd - 1));
            if (node.right != null) queue.add(new Pair(node.right, hd + 1));
        }

        // Collect the bottom view nodes from left to right
        for (int val : map.values()) {
            result.add(val);
        }

        return result;
    }
}
