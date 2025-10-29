class Solution:
    def smallestNumber(self, n: int) -> int:
        num = 1
        while num < n:
            num <<= 1
            num |= 1
        return num
