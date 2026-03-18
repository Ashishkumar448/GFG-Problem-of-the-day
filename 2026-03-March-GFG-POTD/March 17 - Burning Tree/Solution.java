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
    public int minTime(Node root, int target) {
        // Step 1: Build parent map and find target node
        Map<Node, Node> parentMap = new HashMap<>();
        Node targetNode = buildParentMap(root, parentMap, target);
        
        // Step 2: BFS to simulate burning
        Queue<Node> queue = new LinkedList<>();
        Set<Node> visited = new HashSet<>();
        
        queue.offer(targetNode);
        visited.add(targetNode);
        
        int time = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean burned = false;
            
            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                
                // left child
                if (curr.left != null && !visited.contains(curr.left)) {
                    queue.offer(curr.left);
                    visited.add(curr.left);
                    burned = true;
                }
                
                // right child
                if (curr.right != null && !visited.contains(curr.right)) {
                    queue.offer(curr.right);
                    visited.add(curr.right);
                    burned = true;
                }
                
                // parent
                Node parent = parentMap.get(curr);
                if (parent != null && !visited.contains(parent)) {
                    queue.offer(parent);
                    visited.add(parent);
                    burned = true;
                }
            }
            
            if (burned) time++;
        }
        
        return time;
    }
    
    private Node buildParentMap(Node root, Map<Node, Node> parentMap, int target) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        
        Node targetNode = null;
        
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            
            if (curr.data == target) {
                targetNode = curr;
            }
            
            if (curr.left != null) {
                parentMap.put(curr.left, curr);
                queue.offer(curr.left);
            }
            
            if (curr.right != null) {
                parentMap.put(curr.right, curr);
                queue.offer(curr.right);
            }
        }
        
        return targetNode;
    }
}
