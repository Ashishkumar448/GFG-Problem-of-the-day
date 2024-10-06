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

class LinkedList {
    // Function to print nodes in a given circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int key = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            tail.next = head; // Make the list circular
            Solution ob = new Solution();
            Node current = ob.deleteNode(head, key);
            Node rev = ob.reverse(current);
            printList(rev);
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to reverse a circular linked list
    Node reverse(Node head) {
        if (head == null || head.next == head) {
            return head;  // if list is empty or has only one node
        }

        Node prev = null, curr = head, next = null;
        do {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        // Fix head pointer to the new reversed list's first node
        head.next = prev;
        head = prev;
        
        return head;
    }

    // Function to delete a node from the circular linked list
    Node deleteNode(Node head, int key) {
        if (head == null) {
            return null; // if the list is empty
        }

        // If the node to be deleted is the only node
        if (head.data == key && head.next == head) {
            return null;
        }

        Node last = head, d = null;

        // If head is to be deleted
        if (head.data == key) {
            while (last.next != head) { // find the last node
                last = last.next;
            }
            last.next = head.next; // change the next of last node
            head = last.next; // make the next node as head
            return head;
        }

        // Either the node to be deleted is not head or the list has more than one node
        while (last.next != head && last.next.data != key) {
            last = last.next;
        }

        // If node to be deleted was found
        if (last.next.data == key) {
            d = last.next;
            last.next = d.next;
        }

        return head;
    }
}
