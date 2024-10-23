//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int a) {
        data = a;
        next = null;
    }
}


// } Driver Code Ends
/*
Node class is as follows:

class Node {
    int data;
    Node next;

    public Node (int data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution {

    // Return the sum of last k nodes
    public int sumOfLastN_Nodes(Node head, int n) {
        // write code here
         // Step 1: Calculate the length of the linked list
        int length = 0;
        Node current = head;
        while (current != null) {
            length++;
            current = current.next;
        }
        
        // If n is greater than the length of the list, reset n to length
        if (n > length) {
            n = length;
        }
        
        // Step 2: Calculate the starting position
        int startPos = length - n;
        
        // Step 3: Traverse to the starting node and calculate the sum
        current = head;
        int sum = 0;
        int index = 0;
        
        // Traverse the linked list again and sum up the last 'n' nodes
        while (current != null) {
            if (index >= startPos) {
                sum += current.data;
            }
            index++;
            current = current.next;
        }
        
        return sum;
    }
}

//{ Driver Code Starts.

class LinkedList {

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
            int n = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            Solution ob = new Solution();
            System.out.println(ob.sumOfLastN_Nodes(head, n));
        }
    }
}

// } Driver Code Ends
