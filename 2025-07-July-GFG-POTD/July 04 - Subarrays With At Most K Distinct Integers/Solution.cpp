#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countAtMostK(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        int start = 0, result = 0;
        
        for (int end = 0; end < arr.size(); ++end) {
            freqMap[arr[end]]++;

            // Shrink window if more than k distinct elements
            while (freqMap.size() > k) {
                freqMap[arr[start]]--;
                if (freqMap[arr[start]] == 0)
                    freqMap.erase(arr[start]);
                start++;
            }

            result += (end - start + 1);
        }
        
        return result;
    }
};
