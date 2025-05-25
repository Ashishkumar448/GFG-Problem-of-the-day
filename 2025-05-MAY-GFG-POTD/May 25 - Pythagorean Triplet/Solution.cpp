#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();

        // Square all elements
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }

        // Store all squares in a set
        unordered_set<int> squares(arr.begin(), arr.end());

        // Check for pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                if (squares.find(sum) != squares.end()) {
                    return true;
                }
            }
        }

        return false;
    }
};
