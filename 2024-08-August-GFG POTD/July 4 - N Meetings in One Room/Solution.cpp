#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maximumMeetings(int n, vector<int>& start, vector<int>& end) {
        // Combine start and end times into a vector of pairs
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; ++i) {
            meetings.push_back(make_pair(start[i], end[i]));
        }
        // Sort meetings based on the end time
        sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        // Initialize the count of meetings and the end time of the last selected meeting
        int count = 0;
        int last_end_time = 0;
        
        // Iterate over the sorted meetings
        for (const auto& meeting : meetings) {
            if (meeting.first > last_end_time) {
                count++;
                last_end_time = meeting.second;
            }
        }
        
        return count;
    }
};

// Driver code
int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        for (int i = 0; i < n; ++i) {
            cin >> start[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> end[i];
        }
        Solution ob;
        cout << ob.maximumMeetings(n, start, end) << endl;
    }
    return 0;
}
