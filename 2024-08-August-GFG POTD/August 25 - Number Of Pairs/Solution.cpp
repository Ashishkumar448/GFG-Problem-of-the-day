#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(vector<int>& x, vector<int>& y, int M, int N) {
        // Sort y[] so we can use binary search.
        sort(y.begin(), y.end());

        // Count the frequency of each number in y[].
        vector<int> freq(5, 0);
        for (int i = 0; i < N; i++) {
            if (y[i] < 5) {
                freq[y[i]]++;
            }
        }

        long long totalPairs = 0;

        // Traverse all elements in x[].
        for (int i = 0; i < M; i++) {
            totalPairs += countPairsForX(x[i], y, N, freq);
        }

        return totalPairs;
    }

private:
    long long countPairsForX(int x, vector<int>& y, int N, vector<int>& freq) {
        // If x is 0, no valid pairs.
        if (x == 0) return 0;

        // If x is 1, pairs are valid only with y = 0.
        if (x == 1) return freq[0];

        // Find the index of the first number in y[] that is greater than x.
        int idx = upper_bound(y.begin(), y.end(), x) - y.begin();

        // All e
