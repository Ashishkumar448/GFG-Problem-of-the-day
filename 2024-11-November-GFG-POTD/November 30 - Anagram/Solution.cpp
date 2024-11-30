#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check whether two strings are anagram of each other or not.
    bool areAnagrams(string s1, string s2) {
        // If lengths are different, they can't be anagrams
        if (s1.length() != s2.length()) {
            return false;
        }

        // Frequency array for counting character occurrences (a-z)
        vector<int> count(26, 0);

        // Count characters in s1 and s2
        for (size_t i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;  // Increment count for s1 character
            count[s2[i] - 'a']--;  // Decrement count for s2 character
        }

        // If any element is non-zero, the strings are not anagrams
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution obj;
        if (obj.areAnagrams(s1, s2)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
