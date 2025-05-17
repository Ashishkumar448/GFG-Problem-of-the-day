#include <bits/stdc++.h>
using namespace std;

int calculate(int x, int A, int B, int C) {
    return A * x * x + B * x + C;
}

vector<int> sortArray(vector<int>& arr, int A, int B, int C) {
    int n = arr.size();
    vector<int> sorted(n);
    int left = 0, right = n - 1;
    int index = (A >= 0) ? n - 1 : 0;

    while (left <= right) {
        int valLeft = calculate(arr[left], A, B, C);
        int valRight = calculate(arr[right], A, B, C);

        if (A >= 0) {
            if (valLeft > valRight) {
                sorted[index--] = valLeft;
                left++;
            } else {
                sorted[index--] = valRight;
                right--;
            }
        } else {
            if (valLeft < valRight) {
                sorted[index++] = valLeft;
                left++;
            } else {
                sorted[index++] = valRight;
                right--;
            }
        }
    }

    return sorted;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int x;
        while (ss >> x) arr.push_back(x);

        int A, B, C;
        cin >> A >> B >> C;
        cin.ignore();

        vector<int> ans = sortArray(arr, A, B, C);
        for (int val : ans) cout << val << " ";
        cout << "\n~\n";
    }
    return 0;
}
