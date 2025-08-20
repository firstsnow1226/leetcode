class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
        ans = 0

        for i in range(1,n+1):
            for j in range(1,m+1):
                if matrix[i-1][j-1] == 0:
                    dp[i][j] = 0
                    continue
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))
                ans += dp[i][j]

        return ans
