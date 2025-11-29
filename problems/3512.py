class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        tot = 0
        for num in nums:
            tot += num
        return tot % k
