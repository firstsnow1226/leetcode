INF = 10000000
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [INF]*1005
        dp[0] = 0
        dp[1] = 0

        for i in range(2,len(cost)+1):
            dp[i] = min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1])
        
        return dp[len(cost)]


