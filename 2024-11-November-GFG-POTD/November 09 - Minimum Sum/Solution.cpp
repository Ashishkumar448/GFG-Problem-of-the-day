#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string num1 = "", num2 = "";
        bool toggle = true;

        for (int num : arr) {
            if (toggle) {
                if (!(num == 0 && num1.empty())) {
                    num1 += to_string(num);
                }
            } else {
                if (!(num == 0 && num2.empty())) {
                    num2 += to_string(num);
                }
            }
            toggle = !toggle;
        }

        if (num1.empty()) num1 = "0";
        if (num2.empty()) num2 = "0";

        return findSum(num1, num2);
    }

private:
    string findSum(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int carry = 0;
        string result;

        for (int i = 0; i < max(n1, n2) || carry; i++) {
            int digit1 = i < n1 ? str1[n1 - i - 1] - '0' : 0;
            int digit2 = i < n2 ? str2[n2 - i - 1] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> arr;
        string input;
        getline(cin >> ws, input);
        istringstream ss(input);
        int num;
        while (ss >> num) arr.push_back(num);

        Solution obj;
        cout << obj.minSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
