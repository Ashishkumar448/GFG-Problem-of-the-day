//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int count1 = 0, count2 = 0;
        int candidate1 = -1, candidate2 = -1;

        // Phase 1: Find potential candidates for the majority element
        for (int num : arr) {
            if (candidate1 != -1 && candidate1 == num) {
                count1++;
            } else if (candidate2 != -1 && candidate2 == num) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Phase 2: Validate the candidates
        count1 = 0;
        count2 = 0;
        for (int num : arr) {
            if (candidate1 == num) {
                count1++;
            } else if (candidate2 == num) {
                count2++;
            }
        }

        vector<int> result;
        if (count1 > arr.size() / 3) result.push_back(candidate1);
        if (count2 > arr.size() / 3) result.push_back(candidate2);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();  // to ignore the newline after t

    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        vector<int> ans = obj.findMajority(arr);
        for (int n : ans) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
