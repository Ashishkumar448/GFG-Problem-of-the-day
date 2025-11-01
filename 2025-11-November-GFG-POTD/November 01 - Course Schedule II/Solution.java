class Solution {
    public ArrayList<Integer> findOrder(int n, int[][] prerequisites) {
        // adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        // build graph and indegree array
        int[] indegree = new int[n];
        for (int[] pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj.get(prereq).add(course);
            indegree[course]++;
        }

        // queue for courses with no prerequisites
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.add(i);
        }

        ArrayList<Integer> order = new ArrayList<>();

        while (!q.isEmpty()) {
            int curr = q.poll();
            order.add(curr);

            // reduce indegree of adjacent nodes
            for (int next : adj.get(curr)) {
                indegree[next]--;
                if (indegree[next] == 0) q.add(next);
            }
        }

        // if we could not include all courses → cycle exists
        if (order.size() != n) return new ArrayList<>();
        
        return order;
    }
}
