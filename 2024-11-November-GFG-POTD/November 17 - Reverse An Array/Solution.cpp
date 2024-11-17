#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // To ignore the newline after tc input
    while (tc-- > 0) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        obj.reverseArray(arr);

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
