class Solution:
    def kthElement(self, k, arr1, arr2):
        result = sorted(arr1 + arr2)
        return result[k - 1]

if __name__ == "__main__":
    t = int(input().strip())
    while t > 0:
        t -= 1
        k = int(input().strip())
        
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))

        ob = Solution()
        print(ob.kthElement(k, arr1, arr2))
