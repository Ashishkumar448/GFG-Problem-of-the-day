#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(a.begin(), a.end()); // Insert elements of a into a set
        unordered_set<int> resultSet;

        // Check for intersection with b
        for (int num : b) {
            if (setA.count(num)) {
                resultSet.insert(num);
            }
        }

        // Convert resultSet to a vector and return
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        // First array input
        string str1;
        getline(cin, str1);
        vector<int> a;
        int num;
        stringstream ss1(str1);
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Second array input
        string str2;
        getline(cin, str2);
        vector<int> b;
        stringstream ss2(str2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution sol;
        vector<int> res = sol.intersectionWithDuplicates(a, b);

        // Sort the result
        sort(res.begin(), res.end());

        // Print the result
        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (int num : res) {
                cout << num << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}
