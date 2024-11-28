#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        if (n == 0) return 0;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check if the string is entirely whitespaces
        if (i == n) return 0;

        // Step 3: Check for sign
        int sign = 1;  // Default positive
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 4: Read digits and build the number
        int result = 0;
        while (i < n) {
            char c = s[i];

            // If the character is not a digit, break the loop
            if (c < '0' || c > '9') break;

            int digit = c - '0';  // Convert char to int

            // Step 5: Check for overflow before updating result
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();  // Ignore the newline character after the integer input

    while (t > 0) {
        string str;
        getline(cin, str);

        Solution obj;
        int num = obj.myAtoi(str);
        cout << num << endl;
        cout << "~" << endl;
        t--;
    }
    return 0;
}
