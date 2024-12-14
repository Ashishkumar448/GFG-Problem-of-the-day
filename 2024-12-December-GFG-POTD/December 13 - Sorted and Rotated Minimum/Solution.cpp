#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        // Binary search for the minimum element
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the high element, the min is in the right half
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            // Else, the min is in the left half (including mid)
            else {
                high = mid;
            }
        }

        // At the end, low == high, pointing to the minimum element
        return arr[low];
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume the newline after the integer input

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

        cout << ob.findMin(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
