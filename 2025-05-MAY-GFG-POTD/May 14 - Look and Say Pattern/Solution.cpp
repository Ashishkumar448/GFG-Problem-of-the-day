#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string current = "";
            int count = 1;
            char prev = result[0];
            
            for (int j = 1; j < result.length(); j++) {
                if (result[j] == prev) {
                    count++;
                } else {
                    current += to_string(count) + prev;
                    prev = result[j];
                    count = 1;
                }
            }
            current += to_string(count) + prev;
            result = current;
        }
        
        return result;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countAndSay(n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
