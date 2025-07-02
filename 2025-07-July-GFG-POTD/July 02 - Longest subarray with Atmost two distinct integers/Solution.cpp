#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalElements(vector<int>& arr) {
        unordered_map<int, int> map;
        int maxLen = 0, start = 0;

        for (int end = 0; end < arr.size(); end++) {
            map[arr[end]]++;

            while (map.size() > 2) {
                map[arr[start]]--;
                if (map[arr[start]] == 0) {
                    map.erase(arr[start]);
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
