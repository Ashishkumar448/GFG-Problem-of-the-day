class Solution:
    def largestSubset(self, arr):
        n = len(arr)
        arr.sort()
        dp = [1] * n
        chainList = [[arr[i]] for i in range(n)]
        
        for i in range(1, n):
            for j in range(i):
                if arr[i] % arr[j] == 0:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        chainList[i] = chainList[j] + [arr[i]]
                    elif dp[j] + 1 == dp[i]:
                        update = False
                        for k in range(len(chainList[j])):
                            if chainList[j][k] > chainList[i][k]:
                                update = True
                                break
                            elif chainList[j][k] < chainList[i][k]:
                                break
                        if update:
                            chainList[i] = chainList[j] + [arr[i]]
        
        maxLen = 0
        bestChain = []
        for i in range(n):
            if dp[i] > maxLen:
                maxLen = dp[i]
                bestChain = chainList[i]
            elif dp[i] == maxLen:
                for k in range(len(chainList[i])):
                    if chainList[i][k] > bestChain[k]:
                        bestChain = chainList[i]
                        break
                    elif chainList[i][k] < bestChain[k]:
                        break
        
        return bestChain
