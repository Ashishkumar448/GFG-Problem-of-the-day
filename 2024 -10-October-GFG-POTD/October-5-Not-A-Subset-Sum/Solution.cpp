#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long findSmallest(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        // Initialize the smallest number that cannot be formed
        long long res = 1; // Start with 1 as the smallest positive number
        
        // Traverse the array and find the smallest missing number
        for (int i = 0; i < arr.size() && arr[i] <= res; i++) {
            res += arr[i];
        }
        
        return res;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character
    while (t--) {
        string input;
        getline(cin, input);
        vector<int> arr;
        string temp;
        for (char c : input) {
            if (c == ' ') {
                arr.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        arr.push_back(stoi(temp));

        Solution ob;
        long long ans = ob.findSmallest(arr);
        cout << ans << endl;
    }
    return 0;
}
