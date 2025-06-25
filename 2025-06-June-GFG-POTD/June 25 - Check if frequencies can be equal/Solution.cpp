#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool sameFreq(string s) {
        unordered_map<char, int> freqMap;

        // Step 1: Count frequencies of characters
        for (char ch : s) {
            freqMap[ch]++;
        }

        unordered_map<int, int> freqCount;
        // Step 2: Count frequencies of frequencies
        for (auto& pair : freqMap) {
            freqCount[pair.second]++;
        }

        // Case 1: All frequencies same
        if (freqCount.size() == 1) return true;

        // Case 2: Only two different frequencies
        if (freqCount.size() == 2) {
            vector<int> keys;
            for (auto& pair : freqCount) {
                keys.push_back(pair.first);
            }

            int f1 = keys[0], f2 = keys[1];
            int c1 = freqCount[f1], c2 = freqCount[f2];

            // Case A: one frequency is 1 and occurs once
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return true;

            // Case B: frequencies differ by 1 and higher freq occurs once
            if (abs(f1 - f2) == 1) {
                if ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)) return true;
            }
        }

        return false;
    }
};
