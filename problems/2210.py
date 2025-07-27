class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        cnt = 0
        pre2 = nums[0]
        pre = nums[1]
        for i in range(2,len(nums)):
            if nums[i] == nums[i-1]:
                continue
            if (pre-pre2)*(pre-nums[i]) > 0:
                cnt += 1
            pre2 = pre
            pre = nums[i]
        return cnt
