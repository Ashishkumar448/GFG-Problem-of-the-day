//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void rotateArr(int arr[], int d, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);

        vector<int> array;
        int x;
        while (ss >> x) {
            array.push_back(x);
        }

        int d;
        cin >> d; // rotation count
        int n = array.size();
        int arr[n];
        for (int i = 0; i < n; i++) arr[i] = array[i];

        rotateArr(arr, d, n);

        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n~" << endl;
    }
    return 0;
}

// } Driver Code Ends

// Function to rotate an array by d elements in counter-clockwise direction
void rotateArr(int arr[], int d, int n) {
    d = d % n;

    // Step 1: Reverse the first d elements
    reverse(arr, arr + d);

    // Step 2: Reverse the remaining elements
    reverse(arr + d, arr + n);

    // Step 3: Reverse the entire array
    reverse(arr, arr + n);
}
