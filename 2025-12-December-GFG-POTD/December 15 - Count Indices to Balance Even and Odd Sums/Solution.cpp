class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        
        int totalEven = 0, totalOdd = 0;
        
        // Step 1: total sums
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }
        
        int leftEven = 0, leftOdd = 0;
        int count = 0;
        
        // Step 2: try removing each index
        for (int i = 0; i < n; i++) {
            int rightEven = totalEven - leftEven;
            int rightOdd = totalOdd - leftOdd;
            
            if (i % 2 == 0) rightEven -= arr[i];
            else rightOdd -= arr[i];
            
            // After removal, indices on right swap parity
            int newEvenSum = leftEven + rightOdd;
            int newOddSum = leftOdd + rightEven;
            
            if (newEvenSum == newOddSum) {
                count++;
            }
            
            // Update prefix sums
            if (i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }
        
        return count;
    }
};
