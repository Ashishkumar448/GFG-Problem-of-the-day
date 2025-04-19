#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

class Solution {
    TrieNode* root;

public:
    Solution() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = bit ^ 1;
            if (node->child[oppositeBit]) {
                maxXor |= (1 << i);
                node = node->child[oppositeBit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }

    int maxXor(vector<int>& arr) {
        int result = 0;
        for (int num : arr) {
            insert(num);
        }
        for (int num : arr) {
            result = max(result, findMaxXor(num));
        }
        return result;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& num : arr) cin >> num;

        Solution sol;
        cout << sol.maxXor(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
