class Solution {
     public int findMoves(int[] chairs, int[] passengers) {
        // Sort both arrays
        Arrays.sort(chairs);
        Arrays.sort(passengers);
        
        int moves = 0;
        
        // Sum absolute differences
        for (int i = 0; i < chairs.length; i++) {
            moves += Math.abs(chairs[i] - passengers[i]);
        }
        
        return moves;
    }
}
