class Solution {
    public int maxSum(int arr[]) {
        int maxScore = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            int sum = arr[i] + arr[i + 1];
            if (sum > maxScore) {
                maxScore = sum;
            }
        }
        return maxScore;
    }
}
