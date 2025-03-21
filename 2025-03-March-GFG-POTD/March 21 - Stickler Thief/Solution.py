import sys

def find_max_sum(arr):
    if not arr:
        return 0
    if len(arr) == 1:
        return arr[0]
    
    prev2, prev1 = 0, arr[0]
    
    for i in range(1, len(arr)):
        take = arr[i] + prev2
        skip = prev1
        curr = max(take, skip)
        prev2 = prev1
        prev1 = curr
    
    return prev1

if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        arr = list(map(int, sys.stdin.readline().strip().split()))
        print(find_max_sum(arr))
        print("~")
