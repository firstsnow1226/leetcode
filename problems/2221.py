class Solution:
    def CnGETk(self, n, k) -> int:
        return comb(n,k)

    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        sum = 0
        for i in range(len(nums)):
            sum += nums[i] * self.CnGETk(n-1,i)
            sum %= 10
        return sum

