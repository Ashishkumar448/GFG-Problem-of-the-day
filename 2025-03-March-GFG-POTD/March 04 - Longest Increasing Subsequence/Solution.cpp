#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static int lis(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> dp(n); // dp[i] will store the length of LIS ending at index i
        
        // Initialize dp array with 1, as a single element is always an increasing subsequence of length 1
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        
        // Compute the length of LIS ending at each position
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    // Update dp[i] if a longer increasing subsequence is found
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // Find the maximum length in the dp array
        int maxLen = dp[0];
        for (int i = 1; i < n; i++) {
            maxLen = std::max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};

int main() {
    int t; // Number of test cases
    std::cin >> t;
    
    for (int g = 0; g < t; g++) {
        int n; // Number of elements in the array
        std::cin >> n;
        
        std::vector<int> arr(n);
        // Read the input array
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        // Call the solution method and print the result
        std::cout << Solution::lis(arr) << std::endl;
        std::cout << "~" << std::endl;
    }
    
    return 0;
}
