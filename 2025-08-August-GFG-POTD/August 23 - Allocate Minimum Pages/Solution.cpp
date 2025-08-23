class Solution {
public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Edge case: more students than books
        if (k > n) return -1;
        
        int low = 0, high = 0;
        
        // Low = max book, High = sum of all books
        for (int pages : arr) {
            low = max(low, pages);
            high += pages;
        }
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, n, k, mid)) {
                result = mid;
                high = mid - 1;  // try smaller maximum
            } else {
                low = mid + 1;   // need larger maximum
            }
        }
        return result;
    }
    
private:
    bool isPossible(vector<int>& arr, int n, int k, int maxPages) {
        int students = 1;
        int pagesSum = 0;
        
        for (int pages : arr) {
            if (pagesSum + pages > maxPages) {
                students++;
                pagesSum = pages;
                
                if (students > k) return false;
            } else {
                pagesSum += pages;
            }
        }
        return true;
    }
};
