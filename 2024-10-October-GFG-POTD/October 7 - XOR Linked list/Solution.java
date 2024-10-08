import java.io.*;
import java.util.*;

class Node {
    int data;
    Node npx; // XOR of next and previous node

    Node(int data) {
        this.data = data;
        this.npx = null;
    }
}

class XORLinkedList {
    // Utility function to XOR two Node references
    static Node XOR(Node a, Node b) {
        return (Node)((a != null ? a.hashCode() : 0) ^ (b != null ? b.hashCode() : 0));
    }

    // Function to insert a new node at the front of the XOR LinkedList
    static Node insert(Node head, int data) {
        Node newNode = new Node(data);
        newNode.npx = head;

        // If the list is not empty, adjust the previous head's npx
        if (head != null) {
            head.npx = XOR(newNode, head.npx);
        }
        return newNode; // New node becomes the head
    }

    // Function to get the list in forward order
    static List<Integer> getList(Node head) {
        List<Integer> result = new ArrayList<>();
        Node curr = head, prev = null, next;

        // Traverse the XOR linked list
        while (curr != null) {
            result.add(curr.data);
            // Update next node
            next = XOR(prev, curr.npx);
            prev = curr;
            curr = next;
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            Node head = null;
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);

            while (st.hasMoreTokens()) {
                int number = Integer.parseInt(st.nextToken());
                head = insert(head, number);
            }

            List<Integer> list = getList(head);
            // Print list in forward order
            for (int x : list) {
                System.out.print(x + " ");
            }
            System.out.println();

            // Print list in reverse order
            for (int i = list.size() - 1; i >= 0; i--) {
                System.out.print(list.get(i) + " ");
            }
            System.out.println();
        }
    }
}
