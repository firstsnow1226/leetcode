INF = 10000000
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [INF]*200

        dp[0] = triangle[0][0]

        for i in range(1,len(triangle)):
            for j in range(i,-1,-1):
                dp[j] = (dp[j] if j==0 else min(dp[j],dp[j-1])) + triangle[i][j]
                
        return min(dp)
