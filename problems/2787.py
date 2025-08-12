class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        dp = [0]*(n+1)
        dp[0] = 1
        MOD = 1000000007

        for i in range(1,n+1):
            num = pow(i,x)

            if num > n:
                break
            for j in range(n,num-1,-1):
                dp[j] += dp[j-num]
                dp[j] %= MOD
        return dp[n]
