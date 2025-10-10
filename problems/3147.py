MAXN = 100005
INF = -1000000000
class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        dp = [INF] * MAXN
        for i in range(len(energy)):
            dp[i%k] = max(energy[i], dp[i%k]+energy[i])
        ans = INF
        for i in range(k):
            ans = max(ans,dp[i])
        return ans

        
