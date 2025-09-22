MAXN = 101
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = [0] * MAXN
        for x in nums:
            freq[x] += 1
        ans = 0
        max_f = -1

        for x in freq:
            if x > max_f:
                ans = x
                max_f = x
            elif  x == max_f:
                ans += x
        return ans
