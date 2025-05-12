#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Min-heap of available rooms
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        // Min-heap of occupied rooms (endTime, roomNumber)
        using ll = long long;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> occupiedRooms;

        vector<int> roomUsageCount(n, 0);

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            // Free rooms that have completed meetings
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top(); availableRooms.pop();
                roomUsageCount[room]++;
                occupiedRooms.push({end, room});
            } else {
                auto [endTime, room] = occupiedRooms.top(); occupiedRooms.pop();
                roomUsageCount[room]++;
                ll newEnd = endTime + (end - start);
                occupiedRooms.push({newEnd, room});
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomUsageCount[i] > maxMeetings) {
                maxMeetings = roomUsageCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; ++i) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution sol;
        cout << sol.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}
