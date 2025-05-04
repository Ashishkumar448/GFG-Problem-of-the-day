#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int findSubString(string str) {
        int n = str.length();
        if (n == 0) return 0;

        // Step 1: Count unique characters
        unordered_set<char> uniqueChars(str.begin(), str.end());
        int totalUnique = uniqueChars.size();

        // Step 2: Sliding window
        unordered_map<char, int> freqMap;
        int minLen = INT_MAX;
        int start = 0, count = 0;

        for (int end = 0; end < n; ++end) {
            char endChar = str[end];
            freqMap[endChar]++;
            if (freqMap[endChar] == 1) {
                count++;
            }

            while (count == totalUnique) {
                minLen = min(minLen, end - start + 1);
                char startChar = str[start];
                freqMap[startChar]--;
                if (freqMap[startChar] == 0) {
                    count--;
                }
                start++;
            }
        }

        return minLen;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        Solution obj;
        cout << obj.findSubString(str) << endl;
        cout << "~" << endl;
    }
    return 0;
}
