#include <iostream>
using namespace std;

class Solution {
public:
    long long floorSqrt(long long n) {
        if (n == 0 || n == 1) {
            return n;
        }
        
        long long left = 1, right = n, result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long midSquared = mid * mid;
            
            if (midSquared == n) {
                return mid;
            }
            if (midSquared < n) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        long long a;
        cin >> a;
        Solution obj;
        cout << obj.floorSqrt(a) << endl;
        t--;
    }
    return 0;
}
