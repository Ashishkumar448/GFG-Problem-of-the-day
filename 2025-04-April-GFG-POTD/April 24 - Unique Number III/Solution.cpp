#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int getSingle(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        for (auto& entry : freq) {
            if (entry.second == 1) {
                return entry.first;
            }
        }

        return -1; // If not found
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num;
        stringstream ss(line);

        while (ss >> num) {
            arr.push_back(num);
        }

        Solution sol;
        int ans = sol.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
