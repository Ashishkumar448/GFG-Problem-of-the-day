// { Driver Code Starts
import java.io.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class GfG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution obj = new Solution();
            head = obj.addOne(head);
            printList(head);
        }
    }
}
// } Driver Code Ends

/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    // Function to reverse the linked list
    private Node reverseList(Node head) {
        Node prev = null;
        Node curr = head;
        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    // Function to add one to the linked list
    public Node addOne(Node head) {
        // Reverse the linked list
        head = reverseList(head);
        
        Node current = head;
        Node prev = null;
        int carry = 1;  // Initialize carry to 1 since we are adding 1
        
        // Traverse the list and add the carry
        while (current != null) {
            int sum = current.data + carry;
            current.data = sum % 10;  // Update the node's value
            carry = sum / 10;  // Calculate the new carry
            prev = current;
            current = current.next;
        }
        
        // If there is still a carry after processing all nodes
        if (carry > 0) {
            prev.next = new Node(carry);
        }
        
        // Reverse the linked list again to restore the original order
        return reverseList(head);
    }
}
