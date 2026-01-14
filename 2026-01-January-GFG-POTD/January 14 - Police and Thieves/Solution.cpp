class Solution {
public:
    int catchThieves(vector<char>& arr, int k) {
        int n = arr.size();
        vector<int> police, thieves;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else 
                thieves.push_back(i);
        }

        int i = 0, j = 0, caught = 0;

        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                caught++;
                i++;
                j++;
            } else if (thieves[j] < police[i]) {
                j++;
            } else {
                i++;
            }
        }

        return caught;
    }
};
