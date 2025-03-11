#include <iostream>
using namespace std;

class Solution {
public:
    int countWays(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev2 = 1, prev1 = 2, curr = 0;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Number of stairs

        Solution obj;
        cout << obj.countWays(n) << endl;
        cout << "~" << endl;
    }

    return 0;
}
