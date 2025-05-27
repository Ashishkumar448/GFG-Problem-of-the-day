class Solution {
    int index = 0;

    public ArrayList<Integer> leafNodes(int[] preorder) {
        ArrayList<Integer> result = new ArrayList<>();
        findLeaves(preorder, result, Integer.MIN_VALUE, Integer.MAX_VALUE);
        return result;
    }

    private void findLeaves(int[] preorder, ArrayList<Integer> result, int min, int max) {
        if (index >= preorder.length) return;

        int val = preorder[index];
        if (val < min || val > max) return;

        index++;

        int currIndex = index;

        // Left subtree
        findLeaves(preorder, result, min, val - 1);

        // Right subtree
        findLeaves(preorder, result, val + 1, max);

        // If both left and right subtrees didn't consume any new nodes,
        // then this node is a leaf
        if (index == currIndex) {
            result.add(val);
        }
    }
}
