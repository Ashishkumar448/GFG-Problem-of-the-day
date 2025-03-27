#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms required at the railway station
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {  
                // A train is arriving before or at the same time another departs
                platforms++;
                i++;
            } else {  
                // A train has departed, freeing a platform
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr, dep;
        string line;

        // First array input (arrival times)
        cin.ignore();
        getline(cin, line);
        stringstream ss1(line);
        int x;
        while (ss1 >> x) arr.push_back(x);

        // Second array input (departure times)
        getline(cin, line);
        stringstream ss2(line);
        while (ss2 >> x) dep.push_back(x);

        Solution obj;
        cout << obj.findPlatform(arr, dep) << endl;
        cout << "~" << endl;
    }
    return 0;
}
