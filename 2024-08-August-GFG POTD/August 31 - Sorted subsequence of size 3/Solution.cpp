// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Function to check if v2 is a subsequence of v1
bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return j == m;
}

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> res = obj.find3Numbers(arr);
        if (!res.empty() && res.size() != 3) {
            cout << -1 << endl;
        } else {
            if (res.empty()) {
                cout << 0 << endl;
            } else if (res[0] < res[1] && res[1] < res[2] && isSubSequence(arr, res)) {
                cout << 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    // Function to find three numbers such that arr[leftMin[i]] < arr[i] < arr[rightMax[i]]
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        vector<int> result;

        if (n < 3) {
            return result; // If less than 3 elements, no subsequence of size 3 exists.
        }

        // Arrays to store the index of the smallest element to the left and the largest element to the right
        vector<int> leftMin(n, -1);
        vector<int> rightMax(n, -1);

        int minIndex = 0;

        // Fill the leftMin array
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[minIndex]) {
                minIndex = i;
            } else {
                leftMin[i] = minIndex;
            }
        }

        int maxIndex = n - 1;

        // Fill the rightMax array
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[maxIndex]) {
                maxIndex = i;
            } else {
                rightMax[i] = maxIndex;
            }
        }

        // Find the subsequence of size 3
        for (int i = 1; i < n - 1; i++) {
            if (leftMin[i] != -1 && rightMax[i] != -1) {
                result.push_back(arr[leftMin[i]]);
                result.push_back(arr[i]);
                result.push_back(arr[rightMax[i]]);
                return result; // Return the first found subsequence
            }
        }

        return result; // No subsequence found
    }
};
