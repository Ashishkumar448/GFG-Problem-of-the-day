class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        HashSet<Integer> set = new HashSet<>();
        
        // Add elements of array a
        for (int num : a) {
            set.add(num);
        }
        
        // Add elements of array b
        for (int num : b) {
            set.add(num);
        }
        
        // Convert set to ArrayList
        return new ArrayList<>(set);
    }
}
