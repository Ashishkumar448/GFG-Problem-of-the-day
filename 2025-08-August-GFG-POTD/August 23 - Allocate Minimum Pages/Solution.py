class Solution:
    def findPages(self, arr, k):
        n = len(arr)
        
        # Edge case: more students than books
        if k > n:
            return -1
        
        low = max(arr)   # minimum limit
        high = sum(arr)  # maximum limit
        
        result = -1
        while low <= high:
            mid = (low + high) // 2
            
            if self.isPossible(arr, n, k, mid):
                result = mid
                high = mid - 1  # try smaller maximum
            else:
                low = mid + 1   # need larger maximum
                
        return result
    
    def isPossible(self, arr, n, k, maxPages):
        students = 1
        pagesSum = 0
        
        for pages in arr:
            if pagesSum + pages > maxPages:
                students += 1
                pagesSum = pages
                
                if students > k:
                    return False
            else:
                pagesSum += pages
        return True
