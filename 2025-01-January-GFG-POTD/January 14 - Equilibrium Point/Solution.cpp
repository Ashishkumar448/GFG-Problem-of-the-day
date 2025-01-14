//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <vector>
using namespace std;

int findEquilibrium(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num; // Calculate total sum of the array
    }

    int leftSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        totalSum -= arr[i]; // Remaining sum on the right side

        // Check if left sum equals right sum
        if (leftSum == totalSum) {
            return i; // Return the 0-based index of the equilibrium point
        }

        leftSum += arr[i]; // Update left sum for next iteration
    }

    return -1; // Return -1 if no equilibrium point is found
}

int main() {
    int t;
    cin >> t; // Inputting the testcases
    cin.ignore();
    while (t-- > 0) {
        string line;
        getline(cin, line);

        vector<int> arr;
        size_t pos = 0;
        while ((pos = line.find(" ")) != string::npos) {
            arr.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        arr.push_back(stoi(line));

        // Calling findEquilibrium() function
        cout << findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
