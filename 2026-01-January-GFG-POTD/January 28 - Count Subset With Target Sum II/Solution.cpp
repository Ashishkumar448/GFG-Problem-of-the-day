#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        unordered_map<int, int> leftSumCount;
        generateSums(left, 0, 0, leftSumCount);

        int count = 0;
        generateAndCount(right, 0, 0, k, leftSumCount, count);

        return count;
    }

private:
    // Generate all subset sums of left half
    void generateSums(vector<int>& arr, int index, int sum,
                      unordered_map<int, int>& mp) {
        if (index == arr.size()) {
            mp[sum]++;
            return;
        }
        generateSums(arr, index + 1, sum, mp);
        generateSums(arr, index + 1, sum + arr[index], mp);
    }

    // Generate sums of right half and count valid pairs
    void generateAndCount(vector<int>& arr, int index, int sum, int k,
                          unordered_map<int, int>& mp, int& count) {
        if (index == arr.size()) {
            count += mp[k - sum];
            return;
        }
        generateAndCount(arr, index + 1, sum, k, mp, count);
        generateAndCount(arr, index + 1, sum + arr[index], k, mp, count);
    }
};
