#include <vector>
#include <map>

class Solution {
public:
    bool validgroup(std::vector<int>& arr, int k) {
        if (arr.size() % k != 0) return false;

        std::map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int first = freq.begin()->first;

            for (int i = 0; i < k; i++) {
                int current = first + i;
                if (freq.find(current) == freq.end()) {
                    return false;
                }
                freq[current]--;
                if (freq[current] == 0) {
                    freq.erase(current);
                }
            }
        }

        return true;
    }
};
