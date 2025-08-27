class Solution {
    public int countTriangles(int arr[]) {
        int n = arr.length;
        Arrays.sort(arr);  // Step 1: sort the array
        int count = 0;

        // Fix the largest side one by one
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            // Two pointer approach
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    // All elements from i to j-1 with arr[j] form valid triangles
                    count += (j - i);
                    j--; 
                } else {
                    i++;
                }
            }
        }

        return count;
    }
}
