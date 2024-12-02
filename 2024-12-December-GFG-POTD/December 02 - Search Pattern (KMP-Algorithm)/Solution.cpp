#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        vector<int> result;
        int M = pat.length();  // Length of pattern
        int N = txt.length();  // Length of text

        // Step 1: Create the LPS array for the pattern
        vector<int> lps(M);
        computeLPSArray(pat, M, lps);

        // Step 2: Use LPS array to search the pattern in the text
        int i = 0; // Index for txt[]
        int j = 0; // Index for pat[]
        
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == M) {  // Found a match
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

private:
    void computeLPSArray(string pat, int M, vector<int>& lps) {
        int length = 0;  // Length of the previous longest prefix suffix
        int i = 1;
        lps[0] = 0;  // lps[0] is always 0
        
        // Calculate lps[i] for i = 1 to M-1
        while (i < M) {
            if (pat[i] == pat[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string txt, pat;
        cin >> txt >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, txt);
        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (int i = 0; i < res.size(); i++) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
