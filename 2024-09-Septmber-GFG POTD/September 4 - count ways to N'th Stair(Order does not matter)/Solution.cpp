#include <iostream>
using namespace std;

class Solution {
public:
    long nthStair(int n) {
        // As order does not matter, we only need to count distinct combinations
        // For a given n, the result is (n / 2) + 1
        return (n / 2) + 1;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        long ans = ob.nthStair(n);
        cout << ans << endl;
    }
    return 0;
}
