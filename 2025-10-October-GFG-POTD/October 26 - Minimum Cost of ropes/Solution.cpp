#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int minCost(vector<int>& arr) {
        if(arr.size() <= 1) return 0;

        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        for(int rope : arr) pq.push(rope);

        int totalCost = 0;

        while(pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            int cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }

        return totalCost;
    }
};

// Example usage
int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout << Solution::minCost(arr) << endl; // Output: 29
    return 0;
}
