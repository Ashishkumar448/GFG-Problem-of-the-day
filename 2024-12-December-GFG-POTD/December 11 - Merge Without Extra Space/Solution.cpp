#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to merge the arrays.
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int gap = nextGap(n + m);

        while (gap > 0) {
            int i, j;

            // Compare and swap within the first array.
            for (i = 0; i + gap < n; i++) {
                if (a[i] > a[i + gap]) {
                    swap(a[i], a[i + gap]);
                }
            }

            // Compare and swap between arrays.
            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {
                if (a[i] > b[j]) {
                    swap(a[i], b[j]);
                }
            }

            // Compare and swap within the second array.
            if (j < m) {
                for (j = 0; j + gap < m; j++) {
                    if (b[j] > b[j + gap]) {
                        swap(b[j], b[j + gap]);
                    }
                }
            }

            // Calculate the next gap.
            gap = nextGap(gap);
        }
    }

private:
    // Function to calculate the next gap.
    int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    }
};

// Driver Code
int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        Solution ob;
        ob.mergeArrays(a, b);

        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < m; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}
