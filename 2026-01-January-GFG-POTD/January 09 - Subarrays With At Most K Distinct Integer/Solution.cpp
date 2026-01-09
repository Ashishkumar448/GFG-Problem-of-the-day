class Solution {
public:
    int countAtMostK(vector<int>& arr, int k) {
        if (k == 0) return 0;

        unordered_map<int, int> freq;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;

            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]);
                left++;
            }

            count += (right - left + 1);
        }

        return (int)count;
    }
};
