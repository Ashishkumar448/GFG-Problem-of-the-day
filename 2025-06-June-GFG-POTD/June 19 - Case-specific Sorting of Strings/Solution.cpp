#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string caseSort(string s) {
        vector<char> upper, lower;

        // Separate characters by case
        for (char c : s) {
            if (isupper(c))
                upper.push_back(c);
            else
                lower.push_back(c);
        }

        // Sort both vectors
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        // Reconstruct the result string
        string result = "";
        int i = 0, j = 0;

        for (char c : s) {
            if (isupper(c)) {
                result += upper[i++];
            } else {
                result += lower[j++];
            }
        }

        return result;
    }
};
