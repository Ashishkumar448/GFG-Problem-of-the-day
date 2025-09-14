class Solution:
    def startStation(self, gas: list[int], cost: list[int]) -> int:
        n = len(gas)
        total = 0   # total gas - total cost
        tank = 0    # current fuel balance
        start = 0   # candidate starting index

        for i in range(n):
            diff = gas[i] - cost[i]
            total += diff
            tank += diff

            # If tank < 0, can't reach station i+1 from current start
            if tank < 0:
                start = i + 1
                tank = 0

        return start if total >= 0 else -1
