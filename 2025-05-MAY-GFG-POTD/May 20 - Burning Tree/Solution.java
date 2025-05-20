//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

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

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    static void printInorder(Node root) {
        if (root == null) return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            int target = Integer.parseInt(br.readLine());
            Node root = buildTree(s);

            Solution g = new Solution();
            System.out.println(g.minTime(root, target));
            t--;

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


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
}  */
class Solution {
    // Map to store parent references
    private static Map<Node, Node> parentMap = new HashMap<>();

    // Helper method to map parent of each node
    private static void markParents(Node root, Node parent) {
        if (root == null) return;
        if (parent != null) parentMap.put(root, parent);
        markParents(root.left, root);
        markParents(root.right, root);
    }

    // Helper to find the target node
    private static Node findTarget(Node root, int target) {
        if (root == null) return null;
        if (root.data == target) return root;

        Node left = findTarget(root.left, target);
        if (left != null) return left;

        return findTarget(root.right, target);
    }

    public static int minTime(Node root, int target) {
        parentMap.clear();

        // Step 1: Map each node to its parent
        markParents(root, null);

        // Step 2: Find the node corresponding to the target
        Node targetNode = findTarget(root, target);

        // Step 3: BFS to simulate burning
        Queue<Node> queue = new LinkedList<>();
        Set<Node> visited = new HashSet<>();

        queue.add(targetNode);
        visited.add(targetNode);

        int time = -1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean burntNextLevel = false;

            for (int i = 0; i < size; i++) {
                Node current = queue.poll();

                // Check left child
                if (current.left != null && !visited.contains(current.left)) {
                    queue.add(current.left);
                    visited.add(current.left);
                    burntNextLevel = true;
                }

                // Check right child
                if (current.right != null && !visited.contains(current.right)) {
                    queue.add(current.right);
                    visited.add(current.right);
                    burntNextLevel = true;
                }

                // Check parent
                Node parent = parentMap.get(current);
                if (parent != null && !visited.contains(parent)) {
                    queue.add(parent);
                    visited.add(parent);
                    burntNextLevel = true;
                }
            }

            if (burntNextLevel) time++;  // Only increment time if fire spreads
        }

        return time + 1; // Initial time (burning target node) is 0
    }
}
