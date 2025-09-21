class Solution {
    static int maxArea(int mat[][]) {
        int n = mat.length, m = mat[0].length;
        int[] heights = new int[m];
        int maxArea = 0;

        ArrayDeque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            // update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j]++;
            }

            // largest rectangle in histogram (optimized inline)
            stack.clear();
            for (int j = 0; j <= m; j++) {
                int h = (j == m ? 0 : heights[j]);
                while (!stack.isEmpty() && h < heights[stack.peek()]) {
                    int height = heights[stack.pop()];
                    int width = stack.isEmpty() ? j : j - stack.peek() - 1;
                    maxArea = Math.max(maxArea, height * width);
                }
                stack.push(j);
            }
        }
        return maxArea;
    }
}
