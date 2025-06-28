#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> result;

        // Step 1: Sort array b
        sort(b.begin(), b.end());

        // Step 2: For each element in a, perform upper_bound search in b
        for (int num : a) {
            int count = upperBound(b, num);
            result.push_back(count);
        }

        return result;
    }

private:
    // Function to find count of elements <= x using binary search
    static int upperBound(const vector<int>& arr, int x) {
        int low = 0, high = arr.size();

        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low; // number of elements <= x
    }
};
