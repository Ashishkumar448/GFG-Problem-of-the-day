// C++ program to check if strings can form a circle

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int isCircle(vector<string>& arr) {
        // Create adjacency list
        unordered_map<char, vector<char>> adj;
        vector<int> in(26, 0), out(26, 0);

        // Populate adjacency list and degree counts
        for (string& s : arr) {
            char start = s[0];
            char end = s[s.size() - 1];
            adj[start].push_back(end);
            out[start - 'a']++;
            in[end - 'a']++;
        }

        // Check if in-degree and out-degree of each node match
        for (int i = 0; i < 26; i++) {
            if (in[i] != out[i]) {
                return 0;
            }
        }

        // Check if the graph is strongly connected
        if (!isStronglyConnected(arr, adj)) {
            return 0;
        }

        return 1;
    }

private:
    bool isStronglyConnected(vector<string>& arr, unordered_map<char, vector<char>>& adj) {
        // Find the first character to start the DFS from
        char start = arr[0][0];

        // Visited arrays for both directions
        vector<bool> visited(26, false);
        // Forward DFS
        dfs(start, adj, visited);

        // Check if all relevant nodes were visited
        for (string& s : arr) {
            if (!visited[s[0] - 'a']) {
                return false;
            }
        }

        // Transpose graph
        unordered_map<char, vector<char>> transpose;
        for (auto& entry : adj) {
            char u = entry.first;
            for (char v : entry.second) {
                transpose[v].push_back(u);
            }
        }

        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        // Reverse DFS
        dfs(start, transpose, visited);

        // Check if all relevant nodes were visited
        for (string& s : arr) {
            if (!visited[s[0] - 'a']) {
                return false;
            }
        }

        return true;
    }

    void dfs(char node, unordered_map<char, vector<char>>& adj, vector<bool>& visited) {
        visited[node - 'a'] = true;
        for (char neighbor : adj[node]) {
            if (!visited[neighbor - 'a']) {
                dfs(neighbor, adj, visited);
            }
        }
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.isCircle(arr) << endl;
    }
    return 0;
}
