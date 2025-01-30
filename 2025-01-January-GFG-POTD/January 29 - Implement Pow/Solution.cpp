#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
    double power(double b, int e) {
        // Base cases
        if (e == 0) return 1.0; // Anything raised to the power 0 is 1
        if (e < 0) return 1 / power(b, -e); // Handle negative exponents

        // Recursive relation
        double half = power(b, e / 2); // Divide the problem
        if (e % 2 == 0) {
            return half * half; // If even, multiply the half result
        } else {
            return half * half * b; // If odd, multiply an additional base
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        double b;
        int e;
        cin >> b >> e;
        Solution ob;
        cout << fixed << setprecision(5) << ob.power(b, e) << endl;
        cout << "~" << endl;
    }
    return 0;
}
