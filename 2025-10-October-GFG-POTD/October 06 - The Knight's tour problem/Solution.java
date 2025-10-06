class Solution {
    private static final int[] dx = {2, 1, -1, -2, -2, -1, 1, 2};
    private static final int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};

    public ArrayList<ArrayList<Integer>> knightTour(int n) {
        ArrayList<ArrayList<Integer>> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>(Collections.nCopies(n, -1));
            board.add(row);
        }

        // Starting position
        board.get(0).set(0, 0);

        // Try to solve using backtracking
        if (solveKT(0, 0, 1, board, n)) {
            return board;
        } else {
            // Return -1 if no solution exists
            ArrayList<ArrayList<Integer>> res = new ArrayList<>();
            res.add(new ArrayList<>(Arrays.asList(-1)));
            return res;
        }
    }

    private boolean solveKT(int x, int y, int movei, ArrayList<ArrayList<Integer>> board, int n) {
        if (movei == n * n) return true;

        for (int k = 0; k < 8; k++) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isSafe(nextX, nextY, board, n)) {
                board.get(nextX).set(nextY, movei);
                if (solveKT(nextX, nextY, movei + 1, board, n))
                    return true;
                else
                    board.get(nextX).set(nextY, -1); // backtrack
            }
        }
        return false;
    }

    private boolean isSafe(int x, int y, ArrayList<ArrayList<Integer>> board, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n && board.get(x).get(y) == -1);
    }
}
