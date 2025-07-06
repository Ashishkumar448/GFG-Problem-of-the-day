#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        auto cmp = [](const tuple<int, int, int>& x, const tuple<int, int, int>& y) {
            return get<2>(x) < get<2>(y); // max heap based on sum
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> maxHeap(cmp);
        set<pair<int, int>> visited;

        int i = n - 1, j = n - 1;
        maxHeap.push({i, j, a[i] + b[j]});
        visited.insert({i, j});

        vector<int> result;

        while (k-- > 0 && !maxHeap.empty()) {
            auto [i, j, sum] = maxHeap.top(); maxHeap.pop();
            result.push_back(sum);

            if (i - 1 >= 0 && visited.find({i - 1, j}) == visited.end()) {
                maxHeap.push({i - 1, j, a[i - 1] + b[j]});
                visited.insert({i - 1, j});
            }

            if (j - 1 >= 0 && visited.find({i, j - 1}) == visited.end()) {
                maxHeap.push({i, j - 1, a[i] + b[j - 1]});
                visited.insert({i, j - 1});
            }
        }

        return result;
    }
};
