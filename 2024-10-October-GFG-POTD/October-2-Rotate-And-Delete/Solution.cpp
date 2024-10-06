//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm> // for rotate
using namespace std;

class Solution {
public:
    int rotateDelete(vector<int>& arr) {
        int n = arr.size();
        int step = 1;

        while (n > 1) {
            // Rotate: move the last element to the front
            rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());

            // Delete: delete the element at index (n - step)
            int removeIndex = n - step;
            if (removeIndex < 0) {
                removeIndex = 0; // If step exceeds the current size, remove the first element
            }
            arr.erase(arr.begin() + removeIndex);

            // Reduce the size of the list after removal
            n = arr.size();
            step++;
        }

        // Return the last remaining element
        return arr[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends
