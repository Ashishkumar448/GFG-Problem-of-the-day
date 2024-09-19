#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        stringstream ss(str);
        string word;
        vector<string> words;
        
        // Split the string by the dot (.) character
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }
        
        // Use a String to build the reversed string
        string reversed;
        for (int i = words.size() - 1; i >= 0; i--) {
            reversed += words[i];
            // Add a dot after each word except the last one
            if (i > 0) {
                reversed += ".";
            }
        }
        
        return reversed;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        string s;
        getline(cin, s);
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
    return 0;
}
