#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count inversions in the array.
    int inversionCount(vector<int>& arr) {
        vector<int> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    }

private:
    // Function to implement merge sort and count inversions.
    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int mid, inversionCount = 0;

        if (left < right) {
            // Find the middle point.
            mid = left + (right - left) / 2;

            // Recursively count inversions in the left and right halves.
            inversionCount += mergeSortAndCount(arr, temp, left, mid);
            inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);

            // Merge the two halves and count cross inversions.
            inversionCount += mergeAndCount(arr, temp, left, mid, right);
        }

        return inversionCount;
    }

    // Function to merge two halves and count cross inversions.
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;       // Starting index for the left subarray.
        int j = mid + 1;    // Starting index for the right subarray.
        int k = left;       // Starting index to store sorted elements in temp.
        int inversionCount = 0;

        // Merge the two subarrays into temp[].
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // Inversion found because arr[i] > arr[j].
                temp[k++] = arr[j++];
                inversionCount += (mid + 1 - i); // Count all remaining elements in left subarray.
            }
        }

        // Copy remaining elements of the left subarray (if any).
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of the right subarray (if any).
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy sorted elements back into the original array.
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inversionCount;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) arr.push_back(num);

        Solution sol;
        cout << sol.inversionCount(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
