INF = 10000
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n):
            for j in range(n):
                if i == 0:
                    dp[i][j] = matrix[i][j]
                    continue
                dp[i][j] = matrix[i][j] + min(dp[i-1][j],min((INF if j==0 else dp[i-1][j-1]),(INF if j==n-1 else dp[i-1][j+1])))
        return min(dp[n-1])
        
        

