//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Create a priority queue (min-heap) to store the rope lengths
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        
        long long totalCost = 0;
        
        // Combine ropes until only one rope remains
        while (pq.size() > 1) {
            // Remove the two smallest ropes
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            // Calculate the cost of connecting these two ropes
            long long cost = first + second;
            totalCost += cost;
            
            // Add the combined rope back to the priority queue
            pq.push(cost);
        }
        
        // Return the total cost
        return totalCost;
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minCost(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends