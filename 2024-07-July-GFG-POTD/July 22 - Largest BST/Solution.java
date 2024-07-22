// Class to represent a tree node
class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}

// Helper class to store information about the subtree
class Info {
    int size; // size of the subtree
    int max; // max value in the subtree
    int min; // min value in the subtree
    int largestBSTSize; // size of the largest BST
    boolean isBST; // whether the subtree is BST

    Info(int size, int max, int min, int largestBSTSize, boolean isBST) {
        this.size = size;
        this.max = max;
        this.min = min;
        this.largestBSTSize = largestBSTSize;
        this.isBST = isBST;
    }
}

class Solution {
    // Return the size of the largest sub-tree which is also a BST
    static int largestBst(Node root) {
        return largestBstHelper(root).largestBSTSize;
    }

    // Helper method to recursively find the largest BST in the subtree
    static Info largestBstHelper(Node node) {
        if (node == null) {
            return new Info(0, Integer.MIN_VALUE, Integer.MAX_VALUE, 0, true);
        }

        if (node.left == null && node.right == null) {
            return new Info(1, node.data, node.data, 1, true);
        }

        Info leftInfo = largestBstHelper(node.left);
        Info rightInfo = largestBstHelper(node.right);

        Info currentInfo = new Info(0, 0, 0, 0, false);
        currentInfo.size = 1 + leftInfo.size + rightInfo.size;

        if (leftInfo.isBST && rightInfo.isBST && node.data > leftInfo.max && node.data < rightInfo.min) {
            currentInfo.min = Math.min(leftInfo.min, node.data);
            currentInfo.max = Math.max(rightInfo.max, node.data);
            currentInfo.largestBSTSize = currentInfo.size;
            currentInfo.isBST = true;
        } else {
            currentInfo.largestBSTSize = Math.max(leftInfo.largestBSTSize, rightInfo.largestBSTSize);
            currentInfo.isBST = false;
        }

        return currentInfo;
    }

    public static void main(String[] args) {
        /* Constructing the following tree
                  50
               /      \
             30        60
            /  \      /  \
           5   20    45    70
                          /  \
                         65   80 
        */
        Node root = new Node(50);
        root.left = new Node(30);
        root.right = new Node(60);
        root.left.left = new Node(5);
        root.left.right = new Node(20);
        root.right.left = new Node(45);
        root.right.right = new Node(70);
        root.right.right.left = new Node(65);
        root.right.right.right = new Node(80);

        System.out.println("Size of largest BST is " + largestBst(root)); // Output: 5
    }
}
