class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = 1000000007
        dp = [0]*1001
        dp[1] = 1

        for i in range(2,n+1):
            for j in range(delay,forget):
                if i - j <= 0:
                    break
                dp[i] += dp[i-j]

        ans = 0
        for i in range(n,n-forget,-1):
            ans += dp[i]
            ans %= MOD
        
        return ans
        

