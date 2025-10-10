/*
class Node {
    int data;
    Node left,right;
    Node(int d)
    {
        data=d;
        left=right=null;
    }
}
*/

class Solution {
    ArrayList<Integer> zigZagTraversal(Node root) {
        ArrayList<Integer> result = new ArrayList<>();
        
        if (root == null) 
            return result;
        
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        boolean leftToRight = true;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            ArrayList<Integer> level = new ArrayList<>(size);
            
            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                level.add(curr.data);
                
                if (curr.left != null)
                    queue.add(curr.left);
                if (curr.right != null)
                    queue.add(curr.right);
            }
            
            if (!leftToRight) {
                Collections.reverse(level);
            }
            
            result.addAll(level);
            leftToRight = !leftToRight; // toggle direction
        }
        
        return result;
    }
}
