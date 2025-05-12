import heapq

class Solution:
    def mostBooked(self, n, meetings):
        meetings.sort()
        
        available_rooms = list(range(n))
        heapq.heapify(available_rooms)
        
        occupied_rooms = []  # (end_time, room_number)
        room_usage_count = [0] * n
        
        for start, end in meetings:
            while occupied_rooms and occupied_rooms[0][0] <= start:
                _, room = heapq.heappop(occupied_rooms)
                heapq.heappush(available_rooms, room)
            
            if available_rooms:
                room = heapq.heappop(available_rooms)
                room_usage_count[room] += 1
                heapq.heappush(occupied_rooms, (end, room))
            else:
                end_time, room = heapq.heappop(occupied_rooms)
                room_usage_count[room] += 1
                new_end = end_time + (end - start)
                heapq.heappush(occupied_rooms, (new_end, room))
        
        max_count = max(room_usage_count)
        for i in range(n):
            if room_usage_count[i] == max_count:
                return i

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        meetings = [list(map(int, input().split())) for _ in range(m)]
        sol = Solution()
        print(sol.mostBooked(n, meetings))
        print("~")
