// C++ Version of Trie Implementation
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return node->isEndOfWord;
    }

    bool isPrefix(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        Trie trie;
        vector<bool> results;
        for (int i = 0; i < q; i++) {
            int type;
            string s;
            cin >> type >> s;
            if (type == 1)
                trie.insert(s);
            else if (type == 2)
                results.push_back(trie.search(s));
            else if (type == 3)
                results.push_back(trie.isPrefix(s));
        }
        for (bool res : results) {
            cout << (res ? "true" : "false") << " ";
        }
        cout << endl << "~" << endl;
    }
    return 0;
}
