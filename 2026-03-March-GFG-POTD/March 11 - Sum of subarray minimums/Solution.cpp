class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> ple(n), nle(n);
        stack<int> st;
        
        // Previous Less Element
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // Next Less Element
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        long long sum = 0;
        
        for(int i = 0; i < n; i++){
            long long left = i - ple[i];
            long long right = nle[i] - i;
            
            sum += (long long)arr[i] * left * right;
        }
        
        return (int)sum;
    }
};
