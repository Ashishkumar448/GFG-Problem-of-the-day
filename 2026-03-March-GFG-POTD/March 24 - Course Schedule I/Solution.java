class Solution {
    public boolean canFinish(int n, int[][] prerequisites) {
        
        // Step 1: Build graph
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        int[] indegree = new int[n];
        
        for (int[] pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            adj.get(prereq).add(course);
            indegree[course]++;
        }
        
        // Step 2: Queue for nodes with indegree 0
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        
        // Step 3: Process nodes
        int count = 0;
        
        while (!q.isEmpty()) {
            int node = q.poll();
            count++;
            
            for (int neighbor : adj.get(node)) {
                indegree[neighbor]--;
                
                if (indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        
        // Step 4: Check if all nodes processed
        return count == n;
    }
}
