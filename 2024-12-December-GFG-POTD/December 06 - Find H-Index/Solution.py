class Solution:
    def hIndex(self, citations):
        # Sort the citations array in ascending order
        citations.sort()
        n = len(citations)
        
        h_index = 0
        
        # Traverse the sorted array to find the H-Index
        for i in range(n):
            papers_with_citations = n - i
            if citations[i] >= papers_with_citations:
                h_index = papers_with_citations
                break
                
        return h_index

# Driver code
if __name__ == "__main__":
    test_cases = int(input().strip())
    for _ in range(test_cases):
        citations = list(map(int, input().strip().split()))
        ob = Solution()
        result = ob.hIndex(citations)
        print(result)
        print("~")
