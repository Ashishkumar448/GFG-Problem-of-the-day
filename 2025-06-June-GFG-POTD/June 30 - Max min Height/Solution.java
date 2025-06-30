class Solution {
    public int maxMinHeight(int[] arr, int k, int w) {
        int n = arr.length;
        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;

        for (int h : arr) {
            low = Math.min(low, h);
        }
        high = low + k;

        int answer = low;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid)) {
                answer = mid; // try higher
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }

    private boolean isPossible(int[] arr, int k, int w, int target) {
        int n = arr.length;
        int[] water = new int[n + 1];
        long opsUsed = 0;
        long curWater = 0;

        for (int i = 0; i < n; i++) {
            curWater += water[i];
            int currentHeight = arr[i] + (int)curWater;
            if (currentHeight < target) {
                int delta = target - currentHeight;
                opsUsed += delta;
                if (opsUsed > k) return false;

                curWater += delta;
                if (i + w < n) water[i + w] -= delta;
            }
        }

        return true;
    }
}
