//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPathSum(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;

        // Traverse both arrays
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            } else {
                // Both arrays have the same value at i and j
                result += max(sum1, sum2) + arr1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }

        // Add remaining elements of arr1
        while (i < arr1.size()) {
            sum1 += arr1[i++];
        }

        // Add remaining elements of arr2
        while (j < arr2.size()) {
            sum2 += arr2[j++];
        }

        // Add the maximum of the remaining sums to the result
        result += max(sum1, sum2);

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the remaining newline character

    for (int k = 0; k < t; k++) {
        vector<int> arr1, arr2;
        string input;
        
        // Read first array
        getline(cin, input);
        istringstream ss1(input);
        int num;
        while (ss1 >> num) {
            arr1.push_back(num);
        }

        // Read second array
        getline(cin, input);
        istringstream ss2(input);
        while (ss2 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        int ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends
