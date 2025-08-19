class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        cnt = 0
        for num in nums:
            if num == 0:
                cnt += 1
            else:
                ans += cnt*(cnt+1)//2
                cnt = 0
        ans += cnt*(cnt+1)//2
        return ans
