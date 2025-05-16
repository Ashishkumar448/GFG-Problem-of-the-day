//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

public class DriverClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int arr[][] = new int[k][n];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) arr[i][j] = sc.nextInt();
            }
            ArrayList<Integer> range = new Solution().findSmallestRange(arr);
            System.out.println(range.get(0) + " " + range.get(1));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    class Node {
        int data, row, col;
        Node(int data, int row, int col) {
            this.data = data;
            this.row = row;
            this.col = col;
        }
    }

    public ArrayList<Integer> findSmallestRange(int[][] arr) {
        int k = arr.length; // Number of lists
        int n = arr[0].length; // Number of elements in each list

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data);
        int max = Integer.MIN_VALUE;
        
        // Initialize the heap with the first element of each list
        for (int i = 0; i < k; i++) {
            pq.add(new Node(arr[i][0], i, 0));
            max = Math.max(max, arr[i][0]);
        }

        int start = 0, end = Integer.MAX_VALUE;
        
        while (true) {
            Node curr = pq.poll();
            int min = curr.data;

            // Update range if it's smaller than the previous one
            if (max - min < end - start) {
                start = min;
                end = max;
            }

            // If there's a next element in the same list, add it to heap
            if (curr.col + 1 < n) {
                int nextVal = arr[curr.row][curr.col + 1];
                pq.add(new Node(nextVal, curr.row, curr.col + 1));
                max = Math.max(max, nextVal);
            } else {
                break; // One of the lists is exhausted
            }
        }

        ArrayList<Integer> res = new ArrayList<>();
        res.add(start);
        res.add(end);
        return res;
    }
}
