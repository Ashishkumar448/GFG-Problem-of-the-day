#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // Ensure `a` is the smaller array
        if (a.size() > b.size()) {
            return kthElement(b, a, k);
        }

        int n = a.size();
        int m = b.size();

        // Define the binary search range
        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            // Handle out-of-bound elements
            int leftA = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int leftB = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int rightA = (cut1 == n) ? INT_MAX : a[cut1];
            int rightB = (cut2 == m) ? INT_MAX : b[cut2];

            // Check if we found the correct partition
            if (leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB);
            } else if (leftA > rightB) {
                // Move towards the left in `a`
                high = cut1 - 1;
            } else {
                // Move towards the right in `a`
                low = cut1 + 1;
            }
        }

        // If the function reaches here, the input is invalid
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        
        int n, m;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
