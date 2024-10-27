//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        
        // Sort the array to use the two-pointer technique
        sort(arr.begin(), arr.end());
        
        // Iterate through each element to see if it can be the sum of any two others
        for (int i = 0; i < n; i++) {
            int target = arr[i];  // Assume arr[i] is the sum of two other elements
            int left = 0;         // Start pointer
            int right = n - 1;    // End pointer
            
            // Adjust left and right pointers to avoid using the target element itself
            while (left < right) {
                if (left == i) left++;  // Skip if left pointer is on the target element
                if (right == i) right--; // Skip if right pointer is on the target element
                
                // Sum of two elements
                int sum = arr[left] + arr[right];
                
                if (sum == target) {
                    return true; // Found a triplet where sum of two elements equals the third
                } else if (sum < target) {
                    left++; // Move left pointer right to increase the sum
                } else {
                    right--; // Move right pointer left to decrease the sum
                }
            }
        }
        
        return false; // No such triplet found
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t; // Number of test cases
    cin.ignore(); // Ignore newline after reading t
    while (t-- > 0) {
        string line;
        getline(cin, line);
        
        // Parse input line into integers
        vector<int> arr;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
