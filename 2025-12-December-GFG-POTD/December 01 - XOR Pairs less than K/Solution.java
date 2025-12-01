class Solution {
    static class TrieNode {
        TrieNode[] child = new TrieNode[2];
        int count = 0;
    }

    private void insert(TrieNode root, int num) {
        for (int i = 15; i >= 0; i--) {     // since arr[i] ≤ 5*10^4 < 2^16
            int bit = (num >> i) & 1;
            if (root.child[bit] == null)
                root.child[bit] = new TrieNode();
            root = root.child[bit];
            root.count++;
        }
    }

    private int countLessThanK(TrieNode root, int num, int k) {
        int res = 0;
        for (int i = 15; i >= 0; i--) {
            if (root == null) break;
            int bitNum = (num >> i) & 1;
            int bitK = (k >> i) & 1;

            if (bitK == 1) {
                // If k has bit=1, we can take numbers with same bit as num
                if (root.child[bitNum] != null)
                    res += root.child[bitNum].count;
                // Then move to opposite bit, required for XOR < k
                root = root.child[1 - bitNum];
            } else {
                // k has bit=0 → must match bitNum
                root = root.child[bitNum];
            }
        }
        return res;
    }

    public int cntPairs(int[] arr, int k) {
        TrieNode root = new TrieNode();
        int ans = 0;
        for (int num : arr) {
            ans += countLessThanK(root, num, k);
            insert(root, num);
        }
        return ans;
    }
}
