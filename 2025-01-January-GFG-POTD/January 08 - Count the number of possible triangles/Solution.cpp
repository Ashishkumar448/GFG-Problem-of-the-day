#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // Sort the array to simplify the triangle condition check
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int count = 0;

        // Fix the largest side one by one
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            // Use two pointers to find valid pairs
            while (left < right) {
                // Check if the sum of arr[left] and arr[right] is greater than arr[i]
                if (arr[left] + arr[right] > arr[i]) {
                    // All elements between left and right form a valid triangle
                    count += (right - left);
                    right--;
                } else {
                    // Move the left pointer forward
                    left++;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.countTriangles(arr) << endl;
    }
    return 0;
}
