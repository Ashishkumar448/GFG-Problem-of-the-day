#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if the middle element is the key
            if (arr[mid] == key) {
                return mid;
            }

            // Check which part is sorted
            if (arr[low] <= arr[mid]) {
                // Left part is sorted
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1; // Key lies in the left part
                } else {
                    low = mid + 1; // Key lies in the right part
                }
            } else {
                // Right part is sorted
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1; // Key lies in the right part
                } else {
                    high = mid - 1; // Key lies in the left part
                }
            }
        }

        // Key not found
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume the newline after integer input

    Solution ob;

    while (t-- > 0) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num;
        stringstream ss(line);

        while (ss >> num) {
            arr.push_back(num);
        }

        int key;
        cin >> key;
        cin.ignore();

        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }

    return 0;
}
