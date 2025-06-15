class Solution {
    int smallestDivisor(int[] arr, int k) {
        int left = 1;
        int right = 0;
        for (int num : arr) {
            right = Math.max(right, num);
        }

        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (getSum(arr, mid) <= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    private int getSum(int[] arr, int divisor) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + divisor - 1) / divisor; // Equivalent to ceil(num / divisor)
        }
        return sum;
    }
}
