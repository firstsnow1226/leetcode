class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        f = [0] * 10005
        for x in nums:
            if f[x] != 0:
                return x
            f[x] += 1
