class Solution{
public:
    vector<int> countDistinct(int arr[], int k, int n) {
        vector<int> ans;
        unordered_map<int,int> mp;

        // first window
        for(int i = 0; i < k; i++)
            mp[arr[i]]++;

        ans.push_back(mp.size());

        // slide window
        for(int i = k; i < n; i++){
            int outgoing = arr[i - k];
            mp[outgoing]--;
            if(mp[outgoing] == 0)
                mp.erase(outgoing);

            mp[arr[i]]++;
            ans.push_back(mp.size());
        }

        return ans;
    }
};
