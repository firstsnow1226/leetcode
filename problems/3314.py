class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            find = False
            for i in range(num):
                if i | (i+1) == num:
                    ans.append(i)
                    find = True
                    break
            if not find:
                ans.append(-1)
        return ans
