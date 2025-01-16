#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> map; // Map to store the first occurrence of a prefix sum
        int maxLength = 0;          // Stores the maximum length of subarray
        int sum = 0;                // Tracks the cumulative sum
        
        for (int i = 0; i < arr.size(); i++) {
            // Treat 0 as -1 for the purpose of summing
            sum += (arr[i] == 0) ? -1 : 1;
            
            if (sum == 0) {
                // If sum is 0, subarray from start to current index has equal 0's and 1's
                maxLength = i + 1;
            }
            
            // If this sum has been seen before
            if (map.find(sum) != map.end()) {
                // Calculate the length of the subarray
                maxLength = max(maxLength, i - map[sum]);
            } else {
                // Store the first occurrence of this sum
                map[sum] = i;
            }
        }
        
        return maxLength;
    }
};

int main() {
    int T;
    cin >> T; // Read number of test cases
    cin.ignore(); // Ignore the newline after T
    
    while (T--) {
        string line;
        getline(cin, line); // Read the entire line containing the array elements
        
        // Split the line into an array of integers
        vector<int> arr;
        size_t pos = 0;
        while ((pos = line.find(' ')) != string::npos) {
            arr.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        arr.push_back(stoi(line)); // Push the last number
        
        // Create the Solution object
        Solution obj;
        
        // Call maxLen function and print the result
        cout << obj.maxLen(arr) << endl;
    }
    
    return 0;
}
