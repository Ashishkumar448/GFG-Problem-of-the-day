class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];
        int count;
        TrieNode() {
            child[0] = child[1] = nullptr;
            count = 0;
        }
    };

    void insert(TrieNode* root, int num) {
        for (int i = 15; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!root->child[bit])
                root->child[bit] = new TrieNode();
            root = root->child[bit];
            root->count++;
        }
    }

    int countLessThanK(TrieNode* root, int num, int k) {
        int res = 0;
        for (int i = 15; i >= 0; i--) {
            if (!root) break;
            int bitNum = (num >> i) & 1;
            int bitK = (k >> i) & 1;

            if (bitK == 1) {
                if (root->child[bitNum])
                    res += root->child[bitNum]->count;
                root = root->child[1 - bitNum];
            }
            else {
                root = root->child[bitNum];
            }
        }
        return res;
    }

    int cntPairs(vector<int>& arr, int k) {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for (int num : arr) {
            ans += countLessThanK(root, num, k);
            insert(root, num);
        }
        return ans;
    }
};
