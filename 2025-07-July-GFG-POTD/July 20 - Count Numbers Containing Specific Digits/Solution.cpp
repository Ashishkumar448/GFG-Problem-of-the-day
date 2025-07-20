#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        unordered_set<int> includeSet(arr.begin(), arr.end());

        // Step 1: Total n-digit numbers
        int total = 0;
        if (n == 1) {
            total = 9; // 1 to 9
        } else {
            total = 9 * pow(10, n - 1);
        }

        // Step 2: Complement digits
        vector<int> complement;
        for (int i = 0; i <= 9; i++) {
            if (includeSet.find(i) == includeSet.end()) {
                complement.push_back(i);
            }
        }

        // If no complement digits, all numbers are valid
        if (complement.empty()) return total;

        // Step 3: Count invalid numbers
        int len = complement.size();
        int firstDigitChoices = 0;
        for (int d : complement) {
            if (d != 0) firstDigitChoices++;
        }

        int invalid = 0;
        if (n == 1) {
            invalid = firstDigitChoices;
        } else {
            invalid = firstDigitChoices * pow(len, n - 1);
        }

        // Step 4: Valid = Total - Invalid
        return total - invalid;
    }
};
