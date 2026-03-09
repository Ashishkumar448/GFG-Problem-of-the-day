class Solution {
    public String largestSwap(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;

        // maxIdx[i] = index of the largest digit from i to end
        int[] maxIdx = new int[n];
        maxIdx[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[maxIdx[i + 1]]) {
                maxIdx[i] = i;
            } else {
                maxIdx[i] = maxIdx[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] < arr[maxIdx[i]]) {
                char temp = arr[i];
                arr[i] = arr[maxIdx[i]];
                arr[maxIdx[i]] = temp;
                break;
            }
        }

        return new String(arr);
    }
}
