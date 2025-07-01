#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int substrCount(string s, int k) {
        if (s.size() < k) return 0;

        unordered_map<char, int> freqMap;
        int count = 0;

        // Initialize first window
        for (int i = 0; i < k; ++i) {
            freqMap[s[i]]++;
        }
        if (freqMap.size() == k - 1) {
            count++;
        }

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            char outChar = s[i - k];
            freqMap[outChar]--;
            if (freqMap[outChar] == 0) {
                freqMap.erase(outChar);
            }

            char inChar = s[i];
            freqMap[inChar]++;

            if (freqMap.size() == k - 1) {
                count++;
            }
        }

        return count;
    }
};
