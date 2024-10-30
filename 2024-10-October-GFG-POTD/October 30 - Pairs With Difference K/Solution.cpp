#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        
        // Fill the frequency map
        for (int num : arr) {
            freqMap[num]++;
        }
        
        int count = 0;
        
        // Iterate over each unique element in the map
        for (auto& [num, freq] : freqMap) {
            if (k == 0) {
                // Special case: count pairs of the same element if k is 0
                count += (freq * (freq - 1)) / 2;
            } else {
                // Check if num + k is in the map and add valid pairs
                if (freqMap.find(num + k) != freqMap.end()) {
                    count += freq * freqMap[num + k];
                }
            }
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string line;
        getline(cin, line);
        
        vector<int> array;
        int num;
        istringstream iss(line);
        while (iss >> num) {
            array.push_back(num);
        }

        int k;
        cin >> k;
        
        Solution ob;
        int ans = ob.countPairsWithDiffK(array, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
