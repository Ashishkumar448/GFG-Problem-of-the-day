// { Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrements(vector<int>& arr) {
        // Sort the array first
        sort(arr.begin(), arr.end());
        
        // Initialize increment count
        int increments = 0;
        
        // Iterate through the sorted array
        for (int i = 1; i < arr.size(); i++) {
            // If the current element is not greater than the previous element,
            // increment it to make it unique
            if (arr[i] <= arr[i - 1]) {
                int requiredIncrement = arr[i - 1] + 1 - arr[i];
                arr[i] = arr[i - 1] + 1; // Update the current element
                increments += requiredIncrement;
            }
        }
        
        return increments;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin.ignore();
        getline(cin, input);
        istringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution obj;
        int result = obj.minIncrements(arr);
        cout << result << endl;
    }
    return 0;
}
// } Driver Code Ends
