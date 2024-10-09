//{ Driver Code Starts
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& arr) {
        unordered_map<int, int> map;
        int maxDist = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (map.find(arr[i]) != map.end()) {
                int dist = i - map[arr[i]];
                maxDist = max(maxDist, dist);
            } else {
                map[arr[i]] = i;
            }
        }
        return maxDist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string input;
        getline(cin, input);
        vector<int> arr;
        string temp = "";
        for (char c : input) {
            if (c == ' ') {
                arr.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) arr.push_back(stoi(temp));

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
