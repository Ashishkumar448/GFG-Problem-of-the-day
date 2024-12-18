#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findPages(vector<int>& arr, int k) {
        if (arr.size() < k) return -1; // Not enough books for students

        int low = INT_MIN, high = 0;
        for (int pages : arr) {
            low = max(low, pages); // Maximum book size
            high += pages;         // Sum of all pages
        }

        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isFeasible(arr, k, mid)) {
                result = mid; // Valid allocation found, try for a smaller maximum
                high = mid - 1;
            } else {
                low = mid + 1; // Increase the allowed maximum
            }
        }
        return result;
    }

private:
    bool isFeasible(vector<int>& arr, int k, int maxPages) {
        int studentsRequired = 1, currentPages = 0;

        for (int pages : arr) {
            if (currentPages + pages > maxPages) {
                studentsRequired++; // Allocate to a new student
                currentPages = pages;

                if (studentsRequired > k) return false; // More students needed than available
            } else {
                currentPages += pages;
            }
        }
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        Solution sln;
        int ans = sln.findPages(arr, k);
        cout << ans << endl;
    }
    return 0;
}
