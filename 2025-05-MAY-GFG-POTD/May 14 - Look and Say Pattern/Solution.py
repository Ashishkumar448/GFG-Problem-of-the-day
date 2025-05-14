class Solution:
    def countAndSay(self, n: int) -> str:
        if n <= 0:
            return ""
        
        result = "1"
        
        for _ in range(2, n + 1):
            current = ""
            count = 1
            prev = result[0]
            
            for ch in result[1:]:
                if ch == prev:
                    count += 1
                else:
                    current += str(count) + prev
                    prev = ch
                    count = 1
            
            current += str(count) + prev
            result = current
        
        return result

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.countAndSay(n))
        print("~")
