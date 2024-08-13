class Solution:
    
    # Function to find the maximum number of meetings that can
    # be performed in a meeting room.
    def maximumMeetings(self, n, start, end):
        # Combine start and end times into a list of tuples
        meetings = list(zip(start, end))
        # Sort meetings based on the end time
        meetings.sort(key=lambda x: x[1])
        
        # Initialize the count of meetings and the end time of the last selected meeting
        count = 0
        last_end_time = 0
        
        # Iterate over the sorted meetings
        for s, e in meetings:
            # If the start time of the current meeting is greater than the
            # end time of the last selected meeting, select this meeting
            if s > last_end_time:
                count += 1
                last_end_time = e
        
        return count

# Driver code
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        start = list(map(int, input().strip().split()))
        end = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.maximumMeetings(n, start, end))