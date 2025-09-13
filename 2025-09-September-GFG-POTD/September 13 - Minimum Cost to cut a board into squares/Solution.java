class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
        // Sort in descending order
        Arrays.sort(x);
        Arrays.sort(y);
        reverse(x);
        reverse(y);

        int i = 0, j = 0; // pointers for x and y
        int verticalSegments = 1, horizontalSegments = 1;
        int cost = 0;

        while (i < x.length && j < y.length) {
            if (x[i] >= y[j]) {
                // take vertical cut
                cost += x[i] * horizontalSegments;
                verticalSegments++;
                i++;
            } else {
                // take horizontal cut
                cost += y[j] * verticalSegments;
                horizontalSegments++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < x.length) {
            cost += x[i] * horizontalSegments;
            i++;
        }

        // Remaining horizontal cuts
        while (j < y.length) {
            cost += y[j] * verticalSegments;
            j++;
        }

        return cost;
    }

    private static void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
