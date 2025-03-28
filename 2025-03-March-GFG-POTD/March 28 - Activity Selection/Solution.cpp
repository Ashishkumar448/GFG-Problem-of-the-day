#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int activitySelection(vector<int>& start, vector<int>& finish) {
        int n = start.size();
        vector<pair<int, int>> activities;

        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }

        sort(activities.begin(), activities.end());

        int count = 1;
        int lastEndTime = activities[0].first;

        for (int i = 1; i < n; i++) {
            if (activities[i].second > lastEndTime) {
                count++;
                lastEndTime = activities[i].first;
            }
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> start(n), finish(n);
        for (int i = 0; i < n; i++) cin >> start[i];
        for (int i = 0; i < n; i++) cin >> finish[i];

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~" << endl;
    }
    return 0;
}
