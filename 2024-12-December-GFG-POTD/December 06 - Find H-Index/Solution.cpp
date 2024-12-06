#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sort the citations array in ascending order
        sort(citations.begin(), citations.end());
        int n = citations.size();
        
        int hIndex = 0;
        
        // Traverse the sorted array to find the H-Index
        for (int i = 0; i < n; i++) {
            int papersWithCitations = n - i;
            if (citations[i] >= papersWithCitations) {
                hIndex = papersWithCitations;
                break;
            }
        }
        return hIndex;
    }
};

int main() {
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        int n;
        cin >> n;
        vector<int> citations(n);
        for (int i = 0; i < n; i++) {
            cin >> citations[i];
        }
        
        Solution ob;
        int result = ob.hIndex(citations);
        cout << result << endl;
        cout << "~" << endl;
    }
    return 0;
}
