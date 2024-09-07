#include <iostream>
using namespace std;

class Solution {
public:
    long long findNth(long long n) {
        // Convert n to a number in base 9 to skip the digit 9
        long long result = 0;
        long long place = 1;

        // Continue until n is reduced to zero
        while (n > 0) {
            // Append the remainder when divided by 9 to the result
            result += (n % 9) * place;
            // Move to the next digit
            n /= 9;
            // Update the place value to the next power of 10
            place *= 10;
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution ab;
        long long k = ab.findNth(n);
        cout << k << endl;
    }
    return 0;
}
