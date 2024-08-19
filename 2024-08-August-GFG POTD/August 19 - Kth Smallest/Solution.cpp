#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Return the k-1 index element because array index starts from 0
    return arr[k - 1];
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        string line;
        cin.ignore(); // To ignore the newline character after the integer input
        getline(cin, line);

        vector<int> array;
        stringstream ss(line);
        int number;

        while (ss >> number) {
            array.push_back(number);
        }

        int key;
        cin >> key;

        cout << kthSmallest(array, key) << endl;
    }

    return 0;
}
