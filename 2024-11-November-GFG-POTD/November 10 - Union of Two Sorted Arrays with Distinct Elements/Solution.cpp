#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to return a vector containing the union of the two arrays.
    vector<int> findUnion(int a[], int b[], int n, int m) {
        vector<int> result;
        int i = 0, j = 0;

        // Traverse both arrays
        while (i < n && j < m) {
            // Avoid duplicates in result
            if (!result.empty() && result.back() == a[i]) {
                i++;
                continue;
            }
            if (!result.empty() && result.back() == b[j]) {
                j++;
                continue;
            }

            if (a[i] < b[j]) {
                result.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                result.push_back(b[j]);
                j++;
            } else {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }

        // Add remaining elements of a
        while (i < n) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }

        // Add remaining elements of b
        while (j < m) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        // First array input
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Second array input
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        Solution obj;
        vector<int> res = obj.findUnion(a, b, n, m);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
