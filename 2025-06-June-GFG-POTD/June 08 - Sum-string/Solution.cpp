class Solution {
public:
    bool isSumString(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string num1 = s.substr(0, i);
                string num2 = s.substr(i, j - i);
                if (isValid(num1) && isValid(num2)) {
                    if (check(s.substr(j), num1, num2)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool isValid(const string& str) {
        return !(str.length() > 1 && str[0] == '0');
    }

    bool check(string remaining, string num1, string num2) {
        string sum = addStrings(num1, num2);
        if (remaining.substr(0, sum.length()) != sum) return false;
        if (remaining == sum) return true;
        return check(remaining.substr(sum.length()), num2, sum);
    }

    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = i >= 0 ? num1[i--] - '0' : 0;
            int digit2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
