#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Initialize the maximum and minimum product ending at the current position
        int currentMax = arr[0];
        int currentMin = arr[0];
        
        // Initialize the result with the first element
        int maxProduct = arr[0];
        
        // Traverse through the array from the second element
        for (int i = 1; i < n; i++) {
            int temp = currentMax;
            
            // Update currentMax and currentMin based on the current element
            currentMax = max(arr[i], max(currentMax * arr[i], currentMin * arr[i]));
            currentMin = min(arr[i], min(temp * arr[i], currentMin * arr[i]));
            
            // Update the result with the maximum product so far
            maxProduct = max(maxProduct, currentMax);
        }
        
        return maxProduct;
    }
};

int main() {
    int tc;
    cin >> tc;  // Number of test cases
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.maxProduct(arr) << endl;
    }
    return 0;
}
