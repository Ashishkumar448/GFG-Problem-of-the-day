class Solution {
    public String largestSwap(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;

        // Store the index of the rightmost occurrence of each digit
        int[] rightmost = new int[10];
        for (int i = 0; i < 10; i++) rightmost[i] = -1;

        for (int i = 0; i < n; i++) {
            rightmost[arr[i] - '0'] = i;
        }

        // Try to find the first place to swap
        for (int i = 0; i < n; i++) {
            int currDigit = arr[i] - '0';

            // Check for a bigger digit available later
            for (int d = 9; d > currDigit; d--) {
                if (rightmost[d] > i) {
                    // Swap
                    char temp = arr[i];
                    arr[i] = arr[rightmost[d]];
                    arr[rightmost[d]] = temp;

                    return new String(arr);
                }
            }
        }

        // If no swap needed
        return s;
    }
}
