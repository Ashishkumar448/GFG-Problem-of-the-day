//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class LinkedList {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void makeLoop(Node head, Node tail, int x) {
        if (x == 0) return;

        Node curr = head;
        for (int i = 1; i < x; i++) curr = curr.next;

        tail.next = curr;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            ArrayList<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int k = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            makeLoop(head, tail, k);

            Solution ob = new Solution();
            System.out.println(ob.countNodesinLoop(head));
        }
    }
}

// } Driver Code Ends


/*

class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}

*/

// Function should return the length of the loop in LL.

class Solution {
    // Helper function to count the length of the loop
    private int countLoopLength(Node node) {
        Node temp = node;
        int length = 1;
        
        while (temp.next != node) {
            length++;
            temp = temp.next;
        }
        
        return length;
    }
    // Function to find the length of a loop in the linked list.
    public int countNodesinLoop(Node head) {
        // Add your code here.
        Node slow = head, fast = head;
        
        // Step 1: Detect the loop using the Tortoise and Hare method
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            // If slow and fast meet, there's a loop
            if (slow == fast) {
                // Step 2: Find the loop length
                return countLoopLength(slow);
            }
        }
        
        // No loop found
        return 0;
    }
}
