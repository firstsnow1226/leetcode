class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if num % 2 == 0:
                ans.append(-1)
            else:
                now = 1
                while now & num != 0:
                    now *= 2
                now //= 2
                ans.append(num-now)
        return ans
        
