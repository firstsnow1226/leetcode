class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0]*101

        for i in range(1,len(nums)+1):
            dp[i] = max(dp[i-1], (dp[i - 2] if i >= 2 else 0) + nums[i-1] )
        return dp[len(nums)]
        
