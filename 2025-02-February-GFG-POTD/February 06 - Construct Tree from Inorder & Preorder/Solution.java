//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            Node root = null;

            // Read inorder array
            String[] inorderStr = (br.readLine()).trim().split(" ");
            int inorder[] = new int[inorderStr.length];
            for (int i = 0; i < inorderStr.length; i++) {
                inorder[i] = Integer.parseInt(inorderStr[i]);
            }

            // Read preorder array
            String[] preorderStr = (br.readLine()).trim().split(" ");
            int preorder[] = new int[preorderStr.length];
            for (int i = 0; i < preorderStr.length; i++) {
                preorder[i] = Integer.parseInt(preorderStr[i]);
            }

            Solution ob = new Solution();
            root = ob.buildTree(inorder, preorder);
            postOrder(root);
            System.out.println();
        }
    }

    // Function to print postorder traversal of the tree
    public static void postOrder(Node root) {
        if (root == null) return;

        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data + " ");
    }
}

// } Driver Code Ends


/*
class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}
*/

class Solution {
    static int preIndex = 0;
    
    public static Node buildTree(int inorder[], int preorder[]) {
        preIndex = 0; // Reset index for multiple test cases
        Map<Integer, Integer> inorderMap = new HashMap<>();

        // Store the indices of inorder elements for quick lookup
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }

        return constructTree(inorder, preorder, 0, inorder.length - 1, inorderMap);
    }

    private static Node constructTree(int inorder[], int preorder[], int inStart, int inEnd, Map<Integer, Integer> inorderMap) {
        if (inStart > inEnd) {
            return null;
        }

        // Pick the current node from Preorder traversal
        int rootValue = preorder[preIndex++];
        Node root = new Node(rootValue);

        // Find the root index in inorder traversal
        int inIndex = inorderMap.get(rootValue);

        // Recursively build the left and right subtrees
        root.left = constructTree(inorder, preorder, inStart, inIndex - 1, inorderMap);
        root.right = constructTree(inorder, preorder, inIndex + 1, inEnd, inorderMap);

        return root;
    }

}
