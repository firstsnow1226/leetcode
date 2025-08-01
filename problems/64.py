INF = 9000000
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[INF]*(n+1)]*(m+1)
        dp[0][1] = 0
        for i in range(1,m+1):
            for j in range(1,n+1):
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1]
        return dp[m][n] 
