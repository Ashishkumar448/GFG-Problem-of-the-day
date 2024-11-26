#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find the maximum sum of a normal subarray using Kadane's Algorithm
        int maxNormal = kadane(arr);
        
        // If all elements are negative, maxNormal will be the answer
        if (maxNormal < 0) return maxNormal;
        
        // Step 2: Calculate the total sum of the array
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        
        // Step 3: Find the minimum sum of a normal subarray
        // To get the minimum sum, invert the sign of all elements and apply Kadane's Algorithm
        for (int i = 0; i < n; i++) {
            arr[i] = -arr[i];
        }
        
        int maxInverted = kadane(arr);
        
        // Step 4: Calculate the circular sum and return the maximum
        int maxCircular = totalSum + maxInverted;  // Since we inverted the signs, maxInverted gives -minSum
        
        return max(maxNormal, maxCircular);
    }

private:
    // Kadane's algorithm to find the maximum subarray sum
    int kadane(vector<int>& arr) {
        int maxEndingHere = arr[0];
        int maxSoFar = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int temp;
        while (cin.peek() != '\n' && cin >> temp) {
            arr.push_back(temp);
        }
        Solution obj;
        cout << obj.circularSubarraySum(arr) << endl;
        cin.ignore();
    }
    return 0;
}
