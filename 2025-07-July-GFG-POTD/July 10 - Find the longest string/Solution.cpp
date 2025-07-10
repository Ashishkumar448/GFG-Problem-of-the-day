#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
    string word = "";
};

class Solution {
public:
    string longestString(vector<string>& arr) {
        TrieNode* root = new TrieNode();

        // Insert all words into Trie
        for (const string& word : arr) {
            TrieNode* curr = root;
            for (char ch : word) {
                if (!curr->children.count(ch))
                    curr->children[ch] = new TrieNode();
                curr = curr->children[ch];
            }
            curr->isEnd = true;
            curr->word = word;
        }

        // BFS to find the longest valid string
        string result = "";
        queue<TrieNode*> q;
        q.push(root);

        while (!q.empty()) {
            TrieNode* curr = q.front();
            q.pop();

            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (curr->children.count(ch)) {
                    TrieNode* next = curr->children[ch];
                    if (next->isEnd) {
                        q.push(next);
                        if (next->word.length() > result.length() || 
                           (next->word.length() == result.length() && next->word < result)) {
                            result = next->word;
                        }
                    }
                }
            }
        }

        return result;
    }
};
