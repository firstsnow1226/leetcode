class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        now = 0
        cnt = 0
        ans = 0
        for num in nums:
            if num == now:
                cnt += 1
                ans = max(ans,cnt)
            elif num > now:
                now = num
                cnt = 1
                ans = 1
            else:
                cnt = 0

        return ans
