// User function Template for Java

class Solution {
    public int SumofMiddleElements(int[] A, int[] B) {
        int n = A.length;
        int[] merged = new int[2 * n];
        int i = 0, j = 0, k = 0;

        // Merge the two arrays
        while (i < n && j < n) {
            if (A[i] <= B[j]) {
                merged[k++] = A[i++];
            } else {
                merged[k++] = B[j++];
            }
        }

        // If there are remaining elements in A
        while (i < n) {
            merged[k++] = A[i++];
        }

        // If there are remaining elements in B
        while (j < n) {
            merged[k++] = B[j++];
        }

        // Find the middle elements and return their sum
        int middle1 = merged[n - 1]; // First middle element
        int middle2 = merged[n];     // Second middle element

        return middle1 + middle2;
    }
}
