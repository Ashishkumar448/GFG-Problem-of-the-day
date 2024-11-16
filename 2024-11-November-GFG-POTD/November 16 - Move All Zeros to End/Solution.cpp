#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int index = 0; // Index to place the next non-zero element

        // Traverse the array and move non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }

        // Fill the rest of the array with zeros
        while (index < n) {
            arr[index++] = 0;
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        obj.pushZerosToEnd(arr);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
