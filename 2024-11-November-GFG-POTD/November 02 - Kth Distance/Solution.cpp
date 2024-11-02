#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // unordered_set to keep track of elements within the current window of size k
        unordered_set<int> set;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {
            // If the element already exists in the set, a duplicate within k distance is found
            if (set.find(arr[i]) != set.end()) {
                return true;
            }

            // Add the current element to the set
            set.insert(arr[i]);

            // Ensure the size of the set is within the window of size k
            if (i >= k) {
                set.erase(arr[i - k]);
            }
        }

        // If no duplicates are found within the distance of k
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;  // read array size
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;

        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        cout << (res ? "true" : "false") << endl;
        cout << "~" << endl;
    }
    return 0;
}
