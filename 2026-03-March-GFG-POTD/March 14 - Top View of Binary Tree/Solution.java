/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}
*/
class Solution {
    static class Pair {
        Node node;
        int hd;

        Pair(Node n, int h) {
            node = n;
            hd = h;
        }
    }

    public ArrayList<Integer> topView(Node root) {

        ArrayList<Integer> result = new ArrayList<>();
        if(root == null) return result;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(root, 0));

        while(!q.isEmpty()) {
            Pair curr = q.poll();
            Node node = curr.node;
            int hd = curr.hd;

            if(!map.containsKey(hd)) {
                map.put(hd, node.data);
            }

            if(node.left != null) {
                q.add(new Pair(node.left, hd - 1));
            }

            if(node.right != null) {
                q.add(new Pair(node.right, hd + 1));
            }
        }

        for(int val : map.values()) {
            result.add(val);
        }

        return result;
    }
}
