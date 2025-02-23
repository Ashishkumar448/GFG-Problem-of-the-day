#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(arr[i]);
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases
    cin.ignore();
    
    while (t--) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num;
        istringstream iss(line);

        while (iss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        vector<int> res = obj.nextLargerElement(arr);

        for (int i = 0; i < res.size(); i++) {
            if (i != 0) cout << " ";
            cout << res[i];
        }
        cout << endl << "~" << endl;
    }
    return 0;
}
