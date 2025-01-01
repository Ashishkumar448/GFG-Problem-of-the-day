#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // Map to group anagrams
        unordered_map<string, vector<string>> map;

        // Group strings by sorted characters
        for (string str : arr) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        // Collect groups into a result vector
        vector<vector<string>> result;
        for (auto& entry : map) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after the test case input
    while (t--) {
        string line;
        getline(cin, line);

        // Split the input into words
        vector<string> arr;
        string word;
        for (char c : line) {
            if (c == ' ') {
                arr.push_back(word);
                word.clear();
            } else {
                word.push_back(c);
            }
        }
        if (!word.empty()) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);

        // Sort result based on the first word in each group
        sort(result.begin(), result.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[0] < b[0];
        });

        // Print the result
        for (const auto& group : result) {
            for (const string& word : group) {
                cout << word << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}
