class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        
        int max_kadane = kadane(arr);
        
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            arr[i] = -arr[i]; // Invert the elements
        }
        
        int max_inverse_kadane = kadane(arr);
        int max_wrap = total_sum + max_inverse_kadane;
        
        // If all numbers are negative
        if (max_wrap == 0) return max_kadane;
        
        return max(max_kadane, max_wrap);
    }

private:
    int kadane(vector<int>& arr) {
        int max_so_far = arr[0];
        int current_max = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            current_max = max(arr[i], current_max + arr[i]);
            max_so_far = max(max_so_far, current_max);
        }
        return max_so_far;
    }
};
