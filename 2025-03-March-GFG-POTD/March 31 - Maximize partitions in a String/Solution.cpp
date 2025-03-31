#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxPartitions(string s) {
        unordered_map<char, int> lastOccurrence;

        // Step 1: Store last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i]] = i;
        }

        int partitions = 0;
        int maxLast = 0;

        // Step 2: Traverse and create partitions
        for (int i = 0; i < s.length(); i++) {
            maxLast = max(maxLast, lastOccurrence[s[i]]);
            
            if (i == maxLast) {
                partitions++;
            }
        }

        return partitions;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}
