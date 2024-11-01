#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxSum(vector<long long>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Create a new array to store elements in high-low order
        vector<long long> newArr(arr.size());
        
        // Step 2: Fill newArr with elements in alternating high-low order
        int left = 0, right = arr.size() - 1;
        int index = 0;
        
        while (left <= right) {
            if (index % 2 == 0) {
                newArr[index] = arr[left];
                left++;
            } else {
                newArr[index] = arr[right];
                right--;
            }
            index++;
        }
        
        // Step 3: Calculate the sum of absolute differences
        long long maxSum = 0;
        for (size_t i = 0; i < newArr.size() - 1; i++) {
            maxSum += abs(newArr[i] - newArr[i + 1]);
        }
        
        // Add the absolute difference between the last and first element to close the loop
        maxSum += abs(newArr[newArr.size() - 1] - newArr[0]);
        
        return maxSum;
    }
};

// Driver code
int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        vector<long long> arr;
        string line;
        cin.ignore();
        getline(cin, line);
        istringstream iss(line);
        long long num;
        while (iss >> num) {
            arr.push_back(num);
        }

        Solution solution;
        cout << solution.maxSum(arr) << endl;
        cout << "~" << endl;
    }
    
    return 0;
}
