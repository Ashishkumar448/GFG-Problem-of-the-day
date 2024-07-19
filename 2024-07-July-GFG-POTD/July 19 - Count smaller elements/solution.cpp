#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);

        if (n == 0) {
            return result;
        }

        // Step 1: Normalize the numbers (convert them to ranks)
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        map<int, int> rankMap;
        int rank = 0;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = ++rank;
            }
        }

        // Step 2: Use BIT to count the smaller elements
        vector<int> bit(rank + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int currentRank = rankMap[arr[i]];
            result[i] = query(bit, currentRank - 1);
            update(bit, currentRank);
        }

        return result;
    }

private:
    // Function to update the BIT
    void update(vector<int>& bit, int index) {
        while (index < bit.size()) {
            bit[index]++;
            index += index & -index;
        }
    }

    // Function to query the BIT
    int query(const vector<int>& bit, int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, 1, 2, 3, 0, 11, 4};
    vector<int> result = sol.constructLowerArray(arr);
    for (int num : result) {
        printf("%d ", num);
    }
    // Expected Output: 6 1 1 1 0 1 0
    return 0;
}
