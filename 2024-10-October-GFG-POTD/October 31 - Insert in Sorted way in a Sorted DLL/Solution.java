//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
        this.prev = this.next = null;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Ignore the newline character after t

        while (t-- > 0) {
            String input = sc.nextLine(); // Read the entire line for the array elements
            String[] values = input.split(" ");

            Node head = null, tail = null;
            for (String value : values) {
                int x = Integer.parseInt(value);
                if (head == null) {
                    head = new Node(x);
                    tail = head;
                } else {
                    tail.next = new Node(x);
                    tail.next.prev = tail;
                    tail = tail.next;
                }
            }

            int valueToInsert = sc.nextInt();
            if (sc.hasNextLine()) {
                sc.nextLine(); // Ignore the newline character after the value
            }

            Solution obj = new Solution();
            head = obj.sortedInsert(head, valueToInsert);
            printList(head);
        
System.out.println("~");
}

        sc.close();
    }

    public static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

// } Driver Code Ends


/*class of the node of the DLL is as
/*
class Node {
    int data;
    Node prev, next;
    Node(int data) {
        this.data = data;
        this.prev = this.next = null;
    }
}
*/
class Solution {
    public Node sortedInsert(Node head, int x) {
        // add your code here
        Node newNode = new Node(x);

        // Case 1: List is empty
        if (head == null) {
            return newNode;
        }

        // Case 2: Insert at the beginning if x is less than the head's data
        if (x <= head.data) {
            newNode.next = head;
            head.prev = newNode;
            return newNode; // New head of the list
        }

        // Case 3: Traverse and find the appropriate position to insert
        Node current = head;
        while (current.next != null && current.next.data < x) {
            current = current.next;
        }

        // Case 4: Insert after 'current' node
        newNode.next = current.next;
        newNode.prev = current;

        if (current.next != null) {
            current.next.prev = newNode;
        }
        current.next = newNode;

        return head; // Head remains the same
    }
}
