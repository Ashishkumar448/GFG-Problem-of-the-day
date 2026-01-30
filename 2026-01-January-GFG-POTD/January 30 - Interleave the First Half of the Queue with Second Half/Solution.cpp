#include <queue>
using namespace std;

class Solution {
public:
    void rearrangeQueue(queue<int>& q) {
        int n = q.size();
        
        queue<int> firstHalf;
        
        // Move first half elements into firstHalf queue
        for (int i = 0; i < n / 2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }
        
        // Interleave first half and second half
        while (!firstHalf.empty()) {
            q.push(firstHalf.front()); // element from first half
            firstHalf.pop();
            
            q.push(q.front());         // element from second half
            q.pop();
        }
    }
};
