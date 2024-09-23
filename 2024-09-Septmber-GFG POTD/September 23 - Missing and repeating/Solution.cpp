//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr, int n) {
        // Expected sum and sum of squares of first n natural numbers
        long long S_n = (long long)n * (n + 1) / 2;
        long long S_sq_n = (long long)n * (n + 1) * (2 * n + 1) / 6;
        
        // Actual sum and sum of squares of the array
        long long S_arr = 0, S_sq_arr = 0;
        for (int i = 0; i < n; i++) {
            S_arr += arr[i];
            S_sq_arr += (long long)arr[i] * arr[i];
        }
        
        // Calculating the differences
        long long diff1 = S_n - S_arr;          // X - Y
        long long diff2 = S_sq_n - S_sq_arr;    // X^2 - Y^2 = (X - Y) * (X + Y)
        
        long long sumXY = diff2 / diff1;        // X + Y
        
        // Solving for X and Y
        int X = (diff1 + sumXY) / 2;
        int Y = sumXY - X;
        
        return {Y, X};  // Return [repeating, missing]
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findTwoElement(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
