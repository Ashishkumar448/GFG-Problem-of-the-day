#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        string num1 = "", num2 = "";

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }

        string result = addStrings(num1, num2);

        // Remove leading zeros
        int i = 0;
        while (i < result.length() - 1 && result[i] == '0') {
            i++;
        }

        return result.substr(i);
    }

private:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            result += (sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
