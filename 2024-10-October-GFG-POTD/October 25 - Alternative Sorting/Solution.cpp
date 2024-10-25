// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> array1;
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        string token;
        while (ss >> token) {
            array1.push_back(stoi(token));
        }

        vector<int> v;
        int arr[array1.size()];
        int idx = 0;
        for (int i : array1) arr[idx++] = i;

        v = Solution::alternateSort(arr, array1.size());

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    static vector<int> alternateSort(int arr[], int n) {
        // Sort the array
        sort(arr, arr + n);

        vector<int> result;
        int i = 0; // Pointer to the smallest element
        int j = n - 1; // Pointer to the largest element

        while (i <= j) {
            // Append the largest element
            if (i != j) {
                result.push_back(arr[j--]);
            }

            // Append the smallest element
            result.push_back(arr[i++]);
        }

        return result;
    }
};
