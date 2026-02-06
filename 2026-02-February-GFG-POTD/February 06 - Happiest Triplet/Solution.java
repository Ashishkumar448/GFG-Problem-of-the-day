class Solution {
    int[] smallestDiff(int a[], int b[], int c[]) {

        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);

        int i = 0, j = 0, k = 0;

        int bestDiff = Integer.MAX_VALUE;
        int bestSum = Integer.MAX_VALUE;
        int[] result = new int[3];

        while (i < a.length && j < b.length && k < c.length) {

            int x = a[i], y = b[j], z = c[k];

            int currMin = Math.min(x, Math.min(y, z));
            int currMax = Math.max(x, Math.max(y, z));

            int currDiff = currMax - currMin;
            int currSum = x + y + z;

            if (currDiff < bestDiff || 
               (currDiff == bestDiff && currSum < bestSum)) {

                bestDiff = currDiff;
                bestSum = currSum;

                result[0] = x;
                result[1] = y;
                result[2] = z;
            }

            // Move the pointer with the smallest value
            if (currMin == x) i++;
            else if (currMin == y) j++;
            else k++;
        }

        // Sort result in decreasing order
        Arrays.sort(result);
        return new int[]{result[2], result[1], result[0]};
    }
}
