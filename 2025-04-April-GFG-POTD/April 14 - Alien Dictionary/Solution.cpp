#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        for (const string& word : words) {
            for (char c : word) {
                graph[c];
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found = false;

            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            if (!found && w1.length() > w2.length()) return "";
        }

        queue<char> q;
        for (auto& [c, deg] : indegree) {
            if (deg == 0) q.push(c);
        }

        string result;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            result += curr;
            for (char nei : graph[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        return (result.length() == graph.size()) ? result : "";
    }
};

// Driver code for validation can be implemented based on Java logic.
