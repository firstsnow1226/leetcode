class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnt = [0]*10001

        for num in nums:
            cnt[num] += 1
        
        dp = [0]*10001

        for i in range(1,10001):
            dp[i] = max(dp[i-1], (dp[i-2] if i>=2 else 0)+i*cnt[i])
        return dp[10000]


