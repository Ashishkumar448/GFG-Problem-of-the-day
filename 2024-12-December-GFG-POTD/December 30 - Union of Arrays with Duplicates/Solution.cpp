#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnion(vector<int>& a, vector<int>& b) {
        // Create an unordered_set to store the union of the arrays
        unordered_set<int> set;

        // Add elements of array 'a' to the set
        for (int num : a) {
            set.insert(num);
        }

        // Add elements of array 'b' to the set
        for (int num : b) {
            set.insert(num);
        }

        // The size of the set represents the number of distinct elements
        return set.size();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        // Reading the first array
        int n1;
        cin >> n1;
        vector<int> a(n1);
        for (int i = 0; i < n1; i++) {
            cin >> a[i];
        }

        // Reading the second array
        int n2;
        cin >> n2;
        vector<int> b(n2);
        for (int i = 0; i < n2; i++) {
            cin >> b[i];
        }

        // Creating an instance of the Solution class
        Solution ob;

        // Calling findUnion method and printing the result
        cout << ob.findUnion(a, b) << endl;
    }

    return 0;
}
