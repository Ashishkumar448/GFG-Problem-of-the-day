#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string findOrder(string dict[], int N, int K) {
        // Create a graph with K nodes (one for each character)
        vector<vector<int>> adj(K);
        
        // Build the graph
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.length(), word2.length());
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }
        
        // Perform topological sort using BFS (Kahn's Algorithm)
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order += (char)(node + 'a');
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // If the order contains all K characters, return it
        if (order.size() == K) {
            return order;
        } else {
            return ""; // Return empty string if not all characters are included
        }
    }
};

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        string words[n];
        for(int i = 0; i < n; i++) {
            cin >> words[i];
        }
        
        Solution ob;
        string order = ob.findOrder(words, n, k);
        if(order.length() == 0) {
            cout << 0 << endl;
            continue;
        }
        if(order.length() != k) {
            cout << "INCOMPLETE" << endl;
            return 0;
        }
        
        string temp[n];
        for(int i = 0; i < n; i++) {
            temp[i] = words[i];
        }
        
        sort(temp, temp + n, [&](string a, string b) {
            int index1 = 0, index2 = 0;
            for(int i = 0; i < min(a.length(), b.length()) && index1 == index2; i++) {
                index1 = order.find(a[i]);
                index2 = order.find(b[i]);
            }
            if(index1 == index2 && a.length() != b.length()) {
                return a.length() < b.length();
            }
            return index1 < index2;
        });
        
        int flag = 1;
        for(int i = 0; i < n; i++) {
            if(words[i] != temp[i]) {
                flag = 0;
                break;
            }
        }
        
        cout << flag << endl;
    }
    
    return 0;
}
