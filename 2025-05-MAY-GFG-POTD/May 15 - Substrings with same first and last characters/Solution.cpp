#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstring(string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }

        int count = 0;
        for (int f : freq) {
            count += (f * (f + 1)) / 2;
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int result = ob.countSubstring(s);

        cout << result << endl;
        cout << "~" << endl;
    }
    return 0;
}
