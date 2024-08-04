import java.util.*;

class Solution {
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    public int maximumMeetings(int n, int[] start, int[] end) {
        // Combine start and end times into a list of pairs
        List<int[]> meetings = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            meetings.add(new int[]{start[i], end[i]});
        }
        // Sort meetings based on the end time
        meetings.sort((a, b) -> Integer.compare(a[1], b[1]));
        
        // Initialize the count of meetings and the end time of the last selected meeting
        int count = 0;
        int last_end_time = 0;
        
        // Iterate over the sorted meetings
        for (int[] meeting : meetings) {
            if (meeting[0] > last_end_time) {
                count++;
                last_end_time = meeting[1];
            }
        }
        
        return count;
    }
}

// Driver code
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_cases = sc.nextInt();
        while (test_cases-- > 0) {
            int n = sc.nextInt();
            int[] start = new int[n];
            int[] end = new int[n];
            for (int i = 0; i < n; i++) {
                start[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                end[i] = sc.nextInt();
            }
            Solution ob = new Solution();
            System.out.println(ob.maximumMeetings(n, start, end));
        }
        sc.close();
    }
}
