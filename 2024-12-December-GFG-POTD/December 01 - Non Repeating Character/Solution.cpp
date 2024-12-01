#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string s) {
        // Step 1: Create a frequency map to count occurrences of each character
        unordered_map<char, int> freqMap;
        
        // Step 2: Populate the frequency map
        for (char c : s) {
            freqMap[c]++;
        }
        
        // Step 3: Traverse the string again to find the first non-repeating character
        for (char c : s) {
            if (freqMap[c] == 1) {
                return c; // Return the first non-repeating character
            }
        }
        
        // Step 4: If no non-repeating character is found, return '$'
        return '$';
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        Solution obj;
        char ans = obj.nonRepeatingChar(s);
        
        if (ans != '$')
            cout << ans << endl;
        else
            cout << -1 << endl;

        cout << "~" << endl;
    }
    
    return 0;
}
