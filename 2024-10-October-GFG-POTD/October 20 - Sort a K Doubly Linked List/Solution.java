//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class DLLNode {
    int data;
    DLLNode next;
    DLLNode prev;

    DLLNode(int val) {
        data = val;
        next = null;
        prev = null;
    }
}

public class Main {
    public static void push(DLLNode tail, int new_data) {
        DLLNode newNode = new DLLNode(new_data);
        newNode.next = null;
        newNode.prev = tail;

        if (tail != null) {
            tail.next = newNode;
        }
    }

    public static void printList(DLLNode head) {
        if (head == null) {
            return;
        }

        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String[] arr = br.readLine().trim().split(" ");
            int k = Integer.parseInt(br.readLine().trim());

            DLLNode head = new DLLNode(Integer.parseInt(arr[0]));
            DLLNode tail = head;

            for (int i = 1; i < arr.length; i++) {
                push(tail, Integer.parseInt(arr[i]));
                tail = tail.next;
            }

            Solution obj = new Solution();
            DLLNode sorted_head = obj.sortAKSortedDLL(head, k);
            printList(sorted_head);
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public DLLNode sortAKSortedDLL(DLLNode head, int k) {
        if (head == null) return null;

        // Create a min heap (priority queue)
        PriorityQueue<DLLNode> minHeap = new PriorityQueue<>(new Comparator<DLLNode>() {
            public int compare(DLLNode a, DLLNode b) {
                return a.data - b.data;  // Compare based on the node's data
            }
        });

        DLLNode newHead = null, last = null;

        // Insert first k+1 items into the min heap
        DLLNode current = head;
        for (int i = 0; current != null && i <= k; i++) {
            minHeap.add(current);
            current = current.next;
        }

        // Extract the minimum and adjust the doubly linked list
        while (!minHeap.isEmpty()) {
            DLLNode minNode = minHeap.poll();

            // If this is the first node, it becomes the new head
            if (newHead == null) {
                newHead = minNode;
                newHead.prev = null;
                last = newHead;
            } else {
                // Link the new node at the end of the sorted list
                last.next = minNode;
                minNode.prev = last;
                last = minNode;
            }

            // Move to the next node in the original list
            if (current != null) {
                minHeap.add(current);
                current = current.next;
            }
        }

        // The last node's next should be null
        last.next = null;

        return newHead;
    }
}
