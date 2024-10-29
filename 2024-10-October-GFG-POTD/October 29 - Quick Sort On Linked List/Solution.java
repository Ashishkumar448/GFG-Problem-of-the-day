//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class SortLL {
    static Node head;

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            addToTheLast(head);

            for (int i = 1; i < n; i++) {
                int a = Integer.parseInt(str[i]);
                addToTheLast(new Node(a));
            }

            GfG gfg = new GfG();
            Node node = gfg.quickSort(head);

            printList(node);
            System.out.println();
        
System.out.println("~");
}
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }

    public static void addToTheLast(Node node) {
        if (head == null) {
            head = node;
        } else {
            Node temp = head;
            while (temp.next != null) temp = temp.next;
            temp.next = node;
        }
    }
}
// } Driver Code Ends


/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }

}*/
// you have to complete this function
class GfG {
    public static Node quickSort(Node node) {
        // Your code here
        // Base case: if node is null or there is only one element
        if (node == null || node.next == null) {
            return node;
        }
        
        // Partition the list and get the pivot position
        Node[] partitioned = partition(node);
        Node left = quickSort(partitioned[0]); // Recursively sort the left part
        Node pivot = partitioned[1];           // Pivot is already in the correct place
        Node right = quickSort(partitioned[2]); // Recursively sort the right part
        
        // Connect the left, pivot, and right parts
        return concatenate(left, pivot, right);
    }
    
    // Helper method to partition the linked list
    private static Node[] partition(Node node) {
        Node pivot = node;
        Node leftDummy = new Node(0);   // Dummy head for nodes < pivot
        Node rightDummy = new Node(0);  // Dummy head for nodes >= pivot
        Node left = leftDummy;
        Node right = rightDummy;
        
        Node current = node.next;
        
        // Partition nodes around the pivot
        while (current != null) {
            if (current.data < pivot.data) {
                left.next = current;
                left = left.next;
            } else {
                right.next = current;
                right = right.next;
            }
            current = current.next;
        }
        
        // Terminate the lists
        left.next = null;
        right.next = null;
        
        // Return the partitioned lists
        return new Node[] {leftDummy.next, pivot, rightDummy.next};
    }
    
    // Helper method to concatenate left, pivot, and right lists
    private static Node concatenate(Node left, Node pivot, Node right) {
        Node head = pivot;
        
        // Find the end of the left list if it exists
        if (left != null) {
            head = left;
            Node temp = left;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = pivot;
        }
        
        // Attach the right list to the pivot
        pivot.next = right;
        
        return head;

    }
}
