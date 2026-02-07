class Solution {
public:
    int maxSum(int arr[], int n) {
        int arrSum = 0;
        int currVal = 0;

        // Step 1 & 2: calculate total sum and initial value
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }

        int maxVal = currVal;

        // Step 3: compute values for all rotations
        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - n * arr[n - i];
            maxVal = max(maxVal, currVal);
        }

        return maxVal;
    }
};
