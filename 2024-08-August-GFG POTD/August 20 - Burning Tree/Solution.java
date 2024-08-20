//{ Driver Code Starts
// Initial Template for Java

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

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
            if (i >= ip.length)
                break;

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
        if (root == null)
            return;

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

        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution
{
    private static Node findTargetNode(Node root, int target, Map<Node, Node> parentMap) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        Node targetNode = null;
        
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            if (curr.data == target) {
                targetNode = curr;
            }
            if (curr.left != null) {
                parentMap.put(curr.left, curr);
                queue.add(curr.left);
            }
            if (curr.right != null) {
                parentMap.put(curr.right, curr);
                queue.add(curr.right);
            }
        }
        
        return targetNode;
    }

    public static int minTime(Node root, int target) 
    {
        // Map to keep track of parent nodes
        Map<Node, Node> parentMap = new HashMap<>();
        Node targetNode = findTargetNode(root, target, parentMap);

        // BFS to burn the tree
        Queue<Node> queue = new LinkedList<>();
        Set<Node> visited = new HashSet<>();
        
        queue.add(targetNode);
        visited.add(targetNode);
        
        int time = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean flag = false;
            
            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                
                // Check left child
                if (curr.left != null && !visited.contains(curr.left)) {
                    visited.add(curr.left);
                    queue.add(curr.left);
                    flag = true;
                }
                
                // Check right child
                if (curr.right != null && !visited.contains(curr.right)) {
                    visited.add(curr.right);
                    queue.add(curr.right);
                    flag = true;
                }
                
                // Check parent
                if (parentMap.containsKey(curr) && !visited.contains(parentMap.get(curr))) {
                    visited.add(parentMap.get(curr));
                    queue.add(parentMap.get(curr));
                    flag = true;
                }
            }
            
            // If any node was burned, increase the time
            if (flag) time++;
        }
        
        return time;
    }
}
