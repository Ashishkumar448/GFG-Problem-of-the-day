#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int catchThieves(vector<char>& arr, int k) {
        int n = arr.size();
        int count = 0;

        queue<int> police;
        queue<int> thief;

        for (int i = 0; i < n; ++i) {
            if (arr[i] == 'P') {
                police.push(i);
            } else if (arr[i] == 'T') {
                thief.push(i);
            }

            while (!police.empty() && !thief.empty()) {
                int polIndex = police.front();
                int thiefIndex = thief.front();

                if (abs(polIndex - thiefIndex) <= k) {
                    count++;
                    police.pop();
                    thief.pop();
                } else if (thiefIndex < polIndex) {
                    thief.pop();
                } else {
                    police.pop();
                }
            }
        }

        return count;
    }
};
