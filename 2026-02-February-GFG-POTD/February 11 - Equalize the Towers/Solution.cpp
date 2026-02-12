class Solution {
public:
    long long calculateCost(vector<int>& heights, vector<int>& cost, int target) {
        long long total = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            total += 1LL * abs(heights[i] - target) * cost[i];
        }
        
        return total;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        
        long long answer = LLONG_MAX;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            long long cost1 = calculateCost(heights, cost, mid);
            long long cost2 = calculateCost(heights, cost, mid + 1);
            
            answer = min(cost1, cost2);
            
            if (cost1 < cost2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return (int)answer;
    }
};
