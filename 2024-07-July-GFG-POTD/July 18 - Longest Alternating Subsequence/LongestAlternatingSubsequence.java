public class LongestAlternatingSubsequence {
    public static int LAS(int[] arr) {
        int n = arr.length;
        if (n == 0) return 0;

        // Lengths of last increasing and decreasing subsequences
        int inc = 1;
        int dec = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
            } else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
            }
        }

        // The result is the maximum of inc and dec
        return Math.max(inc, dec);
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 4};
        System.out.println("Length of Longest Alternating Subsequence: " + LAS(arr));
    }
}
