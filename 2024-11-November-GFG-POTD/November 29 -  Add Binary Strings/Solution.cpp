#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string s1, string s2) {
        string result = "";
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;

        // Traverse both strings starting from their rightmost digits
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += s1[i] - '0';  // Add s1's digit
                i--;
            }
            if (j >= 0) {
                sum += s2[j] - '0';  // Add s2's digit
                j--;
            }

            result += (sum % 2) + '0';  // Append current bit (0 or 1)
            carry = sum / 2;            // Update carry
        }

        // Reverse the result as the current string is in reverse order
        reverse(result.begin(), result.end());

        // Remove leading zeros
        while (result.length() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.addBinary(a, b) << endl;
        cout << "~" << endl;
    }
    return 0;
}
