#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        vector<int> result = {-1, -1};
        
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // If totalSum is not divisible by 3, we cannot split the array.
        if (totalSum % 3 != 0) {
            return result;
        }
        
        int targetSum = totalSum / 3;
        int runningSum = 0, count = 0;
        
        // Traverse the array to find the split points.
        for (int i = 0; i < arr.size(); i++) {
            runningSum += arr[i];
            
            if (runningSum == targetSum) {
                runningSum = 0; // Reset runningSum for next part
                count++;
                
                // Set the split points when we find the first two equal parts
                if (count == 1) {
                    result[0] = i;
                } else if (count == 2) {
                    result[1] = i + 1;
                    return result;
                }
            }
        }
        
        // If unable to find two split points, return [-1, -1]
        return {-1, -1};
    }
};

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();

    while (testCases-- > 0) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        
        vector<int> arr;
        int num;
        while (iss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        vector<int> result = ob.findSplit(arr);

        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
