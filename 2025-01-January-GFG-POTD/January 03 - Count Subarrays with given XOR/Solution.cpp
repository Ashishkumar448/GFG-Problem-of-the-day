#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        int prefixXOR = 0;
        long long count = 0;

        for (int num : arr) {
            // Update prefixXOR
            prefixXOR ^= num;

            // If prefixXOR itself is equal to k
            if (prefixXOR == k) {
                count++;
            }

            // Check if prefixXOR ^ k exists in map
            int requiredXOR = prefixXOR ^ k;
            if (map.find(requiredXOR) != map.end()) {
                count += map[requiredXOR];
            }

            // Add the current prefixXOR to the map
            map[prefixXOR]++;
        }

        return count;
    }
};

int main() {
    int tc;
    cin >> tc;

    while (tc-- > 0) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }

    return 0;
}
