class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        tot = 0
        for num in nums:
            tot += num
        if tot % 2 == 1:
            return 0
        return len(nums)-1
