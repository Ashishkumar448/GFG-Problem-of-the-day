#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0;            // Pointer for 0s
        int mid = 0;            // Pointer for 1s
        int high = arr.size() - 1; // Pointer for 2s

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of array

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        obj.sort012(arr);

        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
