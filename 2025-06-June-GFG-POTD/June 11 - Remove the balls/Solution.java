class Solution {
    public int findLength(int[] color, int[] radius) {
        // Use a stack to keep track of remaining balls
        Deque<int[]> stack = new ArrayDeque<>();

        for (int i = 0; i < color.length; i++) {
            // Check if the top of the stack has the same color and radius
            if (!stack.isEmpty()) {
                int[] top = stack.peek();
                if (top[0] == color[i] && top[1] == radius[i]) {
                    stack.pop(); // Remove the matching pair
                    continue;
                }
            }
            // Otherwise, push the current ball
            stack.push(new int[]{color[i], radius[i]});
        }

        // Remaining balls in the stack are not removable
        return stack.size();
    }
}
