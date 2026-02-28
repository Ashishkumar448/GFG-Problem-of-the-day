class Solution {
    public static ArrayList<Integer> findClosestPair(int arr1[], int arr2[], int x) {
        int n = arr1.length;
        int m = arr2.length;
        
        int i = 0;           // Pointer for arr1
        int j = m - 1;       // Pointer for arr2
        
        int minDiff = Integer.MAX_VALUE;
        int res1 = 0, res2 = 0;
        
        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            int diff = Math.abs(sum - x);
            
            if (diff < minDiff) {
                minDiff = diff;
                res1 = arr1[i];
                res2 = arr2[j];
            }
            
            if (sum > x) {
                j--;   // Decrease sum
            } else {
                i++;   // Increase sum
            }
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        result.add(res1);
        result.add(res2);
        
        return result;
    }
}
