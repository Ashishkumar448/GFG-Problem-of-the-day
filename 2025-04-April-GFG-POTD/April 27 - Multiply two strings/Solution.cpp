// C++ Version

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiplyStrings(string s1, string s2) {
        bool isNegative = false;
        
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }

        s1 = removeLeadingZeros(s1);
        s2 = removeLeadingZeros(s2);

        if (s1 == "0" || s2 == "0") {
            return "0";
        }

        int n = s1.size();
        int m = s2.size();
        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string ans = "";
        int i = 0;
        while (i < result.size() && result[i] == 0) i++;
        while (i < result.size()) {
            ans += (result[i++] + '0');
        }

        if (isNegative) {
            ans = "-" + ans;
        }

        return ans;
    }

private:
    string removeLeadingZeros(string s) {
        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i++;
        }
        return (i == s.length()) ? "0" : s.substr(i);
    }
};

// Example Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        Solution sol;
        cout << sol.multiplyStrings(a, b) << endl;
        cout << "~" << endl;
    }
    return 0;
}
