import java.util.Arrays;

class Job {
    int id, profit, dead;

    Job(int id, int profit, int dead) {
        this.id = id;
        this.profit = profit;
        this.dead = dead;
    }
}

class Solution {
    // Comparator function to sort jobs according to profit in descending order
    static boolean comparator(Job a, Job b) {
        return a.profit > b.profit;
    }

    // Function to find the maximum profit and the number of jobs done.
    public static int[] JobScheduling(Job arr[], int n) {
        // Sort the jobs array in descending order of profit
        Arrays.sort(arr, (a, b) -> b.profit - a.profit);

        // Find the maximum deadline
        int maxDeadline = -1;
        for (int i = 0; i < n; i++) {
            maxDeadline = Math.max(arr[i].dead, maxDeadline);
        }

        // Initialize an array to store the job slots
        boolean[] slot = new boolean[maxDeadline + 1];

        int countJobs = 0, jobProfit = 0;

        // Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Check for a free slot before the deadline
            for (int j = arr[i].dead; j > 0; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        // Prepare the result to return
        return new int[]{countJobs, jobProfit};
    }

    public static void main(String[] args) {
        Job[] arr = {
            new Job(1, 100, 2),
            new Job(2, 19, 1),
            new Job(3, 27, 2),
            new Job(4, 25, 1),
            new Job(5, 15, 3)
        };

        int n = arr.length;
        int[] result = JobScheduling(arr, n);
        System.out.println("Number of jobs done: " + result[0]);
        System.out.println("Maximum profit: " + result[1]);
    }
}
