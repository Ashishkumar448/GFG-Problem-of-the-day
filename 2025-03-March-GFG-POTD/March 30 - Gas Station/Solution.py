class Solution:
    def startStation(self, gas, cost):
        total_gas, total_cost, start_index, current_gas = 0, 0, 0, 0

        for i in range(len(gas)):
            total_gas += gas[i]
            total_cost += cost[i]
            current_gas += gas[i] - cost[i]

            if current_gas < 0:
                start_index = i + 1
                current_gas = 0

        return start_index if total_gas >= total_cost else -1

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        gas = list(map(int, input().split()))
        cost = list(map(int, input().split()))
        
        obj = Solution()
        print(obj.startStation(gas, cost))
        print("~")
