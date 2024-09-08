#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to sort an array of 0s, 1s, and 2s
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high) {
            switch (arr[mid]) {
                case 0:
                    swap(arr[low], arr[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr[mid], arr[high]);
                    high--;
                    break;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        ob.sort012(arr);

        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
