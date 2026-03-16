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
    public int countAllPaths(Node root, int k) {
        HashMap<Long, Integer> map = new HashMap<>();
        map.put(0L, 1); // base case
        
        return dfs(root, 0, k, map);
    }
    
    private int dfs(Node node, long currSum, int k, HashMap<Long, Integer> map) {
        if (node == null) return 0;
        
        currSum += node.data;
        
        // Check if there exists a prefix sum we can subtract
        int count = map.getOrDefault(currSum - k, 0);
        
        // Add current sum to map
        map.put(currSum, map.getOrDefault(currSum, 0) + 1);
        
        // Traverse left and right
        count += dfs(node.left, currSum, k, map);
        count += dfs(node.right, currSum, k, map);
        
        // Backtrack (important!)
        map.put(currSum, map.get(currSum) - 1);
        
        return count;
    }
}
