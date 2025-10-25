#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        double originalSum = 0;
        priority_queue<double> pq;  // max-heap

        for (int num : arr) {
            originalSum += num;
            pq.push((double)num);
        }

        double target = originalSum / 2.0;
        double currentSum = originalSum;
        int operations = 0;

        while (currentSum > target) {
            double largest = pq.top();
            pq.pop();
            double half = largest / 2.0;
            currentSum -= half;
            pq.push(half);
            operations++;
        }

        return operations;
    }
};
