#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        // Store jobs as pairs (profit, deadline)
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by profit in descending order
        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<bool> slot(maxDeadline + 1, false); // Track available slots

        int jobCount = 0, maxProfit = 0;
        for (auto job : jobs) {
            int d = job.second, p = job.first;

            // Find the latest available slot before deadline
            for (int j = d; j > 0; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    jobCount++;
                    maxProfit += p;
                    break;
                }
            }
        }

        return {jobCount, maxProfit};
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> deadline(n), profit(n);

        for (int i = 0; i < n; i++) cin >> deadline[i];
        for (int i = 0; i < n; i++) cin >> profit[i];

        Solution obj;
        vector<int> result = obj.jobSequencing(deadline, profit);
        cout << result[0] << " " << result[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
