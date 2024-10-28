#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> removeDuplicate(int arr[], int n) {
        // Using set to remove duplicates and maintain order
        set<int> uniqueElements;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (uniqueElements.find(arr[i]) == uniqueElements.end()) {
                uniqueElements.insert(arr[i]);
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution sol;
        vector<int> result = sol.removeDuplicate(arr, n);
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
