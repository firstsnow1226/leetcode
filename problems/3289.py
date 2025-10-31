class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        cnt = [0]*105
        ans = []
        for num in nums:
            cnt[num] += 1
            if cnt[num] > 1:
                ans.append(num)
        return ans
